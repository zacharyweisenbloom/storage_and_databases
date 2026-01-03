#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
class Worker {

  int socketfd;
  int server_sock;
  struct sockaddr_in addr{};

public:
  Worker(int socket_int) { server_sock = socket_int; }

  int connect_to_server(int server_port) {

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
      std::cout << "socket failed too bind" << std::endl;
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(server_port);

    if (connect(server_sock, (sockaddr *)&addr, sizeof(addr))) {
      return 1;
    }
    return 0;
  }
};

int main() { Worker worker{6767}; }
