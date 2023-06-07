#include <iostream>
#include <vector>
#include <list>
#include "xrange.h"
#include "zip.h"
#include "algorithms.h"

int main() {
  for (const auto& i : xrange(1.5, 10.5)) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  auto x = xrange(0,5,2);
  std::vector<int> v{x.begin(), x.end()};
  for(auto i:v) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
  auto x2 = xrange(1,5,2);
  std::vector<int> v2{x2.begin(), x2.end()};
  for(auto i:v2) {
    std::cout << i << ' ';
  }
  std::cout << '\n';


  std::list<std::string> l1{"a", "b", "c", "d"};
  auto t = l1.end();
  t--;
  for(auto value : zip(v, l1)) {
    std::cout << value.first << " " << value.second << std::endl;
  }



  return 0;
}