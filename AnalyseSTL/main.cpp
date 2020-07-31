#include <iostream>
#include "MyVector.h"
#include <list>
int main() {
  std::list<int> my_list(5,5);
  MyVector<int> my_vector(5,1);
  int x = 1;
  my_vector.push_back(x);
  std::cout << my_vector.capacity() << my_vector.empty();
  my_vector.erase(my_vector.begin() + 5);
//  std::for_each(my_vector.begin(), my_vector.end(), [](const int i) { std::cout << i << std::ends; }
  std::cout << my_vector.at(1);
}

