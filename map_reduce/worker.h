#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

enum class WorkerType { MapWorker, ReduceWorker };

class Worker {

  int socketfd;
  int server_port;
  struct sockaddr_in addr{};

  // map is zero reduce is one
  WorkerType type;

public:
  Worker(int port);
  int get_data(std::string file_path);
  int map();
  int reduce();
  int connect_to_server(int port = 6767);
};
