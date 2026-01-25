#include "protocol.h"
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

class WorkerNode {

  int server_port;
  struct sockaddr_in addr{};

  // map is zero reduce is one
  WorkerType type;

public:
  int socketfd;

  WorkerNode(int port);
  int connect_to_server(int port = 6767);
  int get_data(std::string file_path);
};
