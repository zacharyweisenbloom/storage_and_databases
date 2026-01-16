#include <vector>

class ResourceManager {
  std::vector<struct Worker> client_list;

public:
  int start_server(int server_port = 6767);
};
