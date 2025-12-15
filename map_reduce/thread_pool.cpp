#include <iostream>

class ThreadPool {
public:
  void start();
  void queue_job(std::function<void()> &job);
  void stop();
  void busy();

private:
  void thread_loop();
  bool should_terminate = false;
  std::mutex queue_mutex;
};
