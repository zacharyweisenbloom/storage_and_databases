#include "worker.h"
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

Worker::Worker(int port) { server_port = port; }

int Worker::connect_to_server(int port) {

  server_port = port;

  int socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0) {
    std::cout << "socket failed too bind" << std::endl;
  }
  addr.sin_family = AF_INET;
  addr.sin_port = htons(server_port);
  inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

  if (connect(socketfd, (sockaddr *)&addr, sizeof(addr)) < 0) {
    std::cout << "failed to connect" << std::endl;
    return 1;
  }
  std::cout << "connection succeeded" << std::endl;
  return 0;
}

int main() {
  Worker worker{6767};
  worker.connect_to_server(6767);
}
