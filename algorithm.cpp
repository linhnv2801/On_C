// adjacent_find example
#include <iostream>     // std::cout
#include <algorithm>    // std::adjacent_find
#include <vector>       // std::vector

bool myfunction (int i, int j) {
  return (i==j);
}

void print(int i) {
	std::cout << ' ' << i;
}

int main () {
  int myints[] = {5,20,5,30,31,20,10,11,11};
  std::vector<int> myvector (myints,myints+9);
  std::vector<int>::iterator it;
	
  for_each(myvector.begin(), myvector.end(),print);
  std::cout << "\n";	
  
  // using default comparison:
  it = std::adjacent_find (myvector.begin(), myvector.end());

  if (it!=myvector.end())
    std::cout << "the first pair of repeated elements are: " << *it << '\n';

  //using predicate comparison:
  it = std::adjacent_find (++it, myvector.end(), myfunction);

  if (it!=myvector.end())
    std::cout << "the second pair of repeated elements are: " << *it << '\n';

  return 0;
}
