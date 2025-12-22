#include <functional>
#include <iostream>
int main() {

  std::function<int()> b = [] { return 5; };

  int x = static_cast<int>(b());
}
