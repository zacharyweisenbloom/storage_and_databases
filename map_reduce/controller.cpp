#include <arpa/inet.h>
#include <cstdio>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h> //bind
#include <vector>

// Connect to map and reduce workers. have a total number of map and reduce
// workers. parse and break up tasks. take input file and break it up. execute
// map and reduce workers

// protocol: <byte length, json data>
// default port 6967

class BuildCluster {
public:
  int port = 6967;
  BuildCluster(std::string build_file) {

    std::cout << build_file << std::endl;

    // create the socket construct
    //  AF_INET = IPV4
    //  SOCK_STREAM = TCP
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    // will accept connections from anything
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(socketfd, (sockaddr *)&addr, sizeof(addr)) < 0) {
      perror("bind failed");
      std::exit(EXIT_FAILURE);
    }
  }
};

int main(int argc, char *argv[]) {

  std::vector<std::string> input(argv, argv + argc);

  if (input.size() != 2) {

    std::cout << "incorrect number of arguments " << input.size() << std::endl;

    exit(1);
  }

  std::string file_path = input[1];

  BuildCluster cluster = BuildCluster(file_path);
}
