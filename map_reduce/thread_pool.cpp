#include <iostream>
#include <thread>
class ThreadPool {
public:
  void start();
  void queue_job(std::function<void()> &job);

  void stop();
  bool busy();
private:
  void thread_loop();
  bool should_terminate = false;
  std::mutex queue_mutex;
  std::condition_variable mutex_condition;
  std::vector<std::thread> threads;
  std::queue<std::function<void()>> jobs;
};

void ThreadPool::start() {
  const u_int32_t num_threads = std::thread::hardware_concurrency();
  for (u_int32_t ii = 0; ii < num_threads; ++ii) {
    threads.emplace_back(std::thread(&ThreadPool::thread_loop, this));
  }
}

void ThreadPool::thread_loop() {
  while (true) {
    std::function<void()> job;
    {
      std::unique_lock<std::mutex> lock(queue_mutex);

      mutex_condition.wait(
          lock, [this] { return !jobs.empty() || should_terminate; });
      if (should_terminate) {
        return;
      }
      job = jobs.front();
      jobs.pop();
    }
    job();
  }
}

void ThreadPool::queue_job(std::function<void()> &job) {
  {
    std::unique_lock<std::mutex> lock(queue_mutex);
    jobs.push(job);
  }
  mutex_condition.notify_one();
}

bool ThreadPool::busy() {
  bool pool_busy;
  {
    std::unique_lock<std::mutex> lock(queue_mutex);
    pool_busy = !jobs.empty();
  }
  return pool_busy;
}

void ThreadPool::stop() {
  {
    std::unique_lock<std::mutex> lock(queue_mutex);
    should_terminate = true;
  }
  mutex_condition.notify_all();
  for (std::thread &active_thread : threads) {
    active_thread.join();
  }
  threads.clear();
}
