// array::begin example
#include <iostream>
#include <array>

int main ()
{
  std::array<int,6> myarray = { 2, 16, 77, 34, 50 };
  myarray[5] = 60;

  std::cout << "myarray contains:";
  for ( auto it = myarray.begin(); it != myarray.end(); ++it )
    std::cout << ' ' << *it;
  std::cout << '\n';
  
  for ( auto it = myarray.cbegin(); it != myarray.cend(); ++it )
  {
    std::cout << ' ' << *it;   // cannot modify *it
  }

  std::cout << '\n';
  
  std::array<int,5> first = {10, 20, 30, 40, 50};
  std::array<int,5> second = {11, 22, 33, 44, 55};

  first.swap (second);

  std::cout << "first:";
  for (int& x : first) std::cout << ' ' << x;
  std::cout << '\n';

  std::cout << "second:";
  for (int& x : second) std::cout << ' ' << x;
  std::cout << '\n';


  return 0;
}
