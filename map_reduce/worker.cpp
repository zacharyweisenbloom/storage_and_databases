#include <iostream>
#include <vector>
#include <arpa/intet.h>
class Worker{
public:
  Worker(int server_port){

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0){
      std::perror << "socket failed too bind" << std::endl;
      return 1;


    
    }
    



  }

 
}




