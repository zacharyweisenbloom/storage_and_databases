#include <iostream>

// Select is used to listen to multiple file descriptors
#include <sys/select.h>

void help() { std::cout << "./client <port>" << std::endl; }

int main(int argc, char **argv) {

  if (argc != 2) {
    help();
    exit(EXIT_FAILURE);
  }
  fdset
}
