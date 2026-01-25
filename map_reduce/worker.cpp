#include "worker.h"
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

WorkerNode::WorkerNode(int port) { server_port = port; }

int WorkerNode::connect_to_server(int port) {

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
  // Establish connection with server
  WorkerNode worker_node{6767};
  if (worker_node.connect_to_server(6767) != 0) {
    exit(-1);
  }

  std::vector<char> buf(4096);

  // Fixed length header, follwoed by variable length message.
  while (true) {
    ssize_t n = recv(worker_node.socketfd, &buf, 4096, 0);
  }
}
