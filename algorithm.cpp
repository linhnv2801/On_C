// partial_sort example
#include <iostream>     // std::cout
#include <algorithm>    // std::partial_sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i>j); }

void print0(int x)
{
    std::cout << x << "\t";
}

template <typename T>
void print(const std::vector<T> t){
	for_each(t.begin(), t.end(), print0);
	std::cout << "\n";
}

int main () {
  int myints[] = {9,8,7,6,5,4,3,2,1};
  std::vector<int> myvector (myints, myints+sizeof(myints)/sizeof(int));

  // using default comparison (operator <):
  std::partial_sort (myvector.begin(), myvector.begin()+5, myvector.end());

  // print out content:
  std::cout << "myvector contains:";
  print(myvector);

  // using function as comp
  std::partial_sort (myvector.begin(), myvector.begin()+5, myvector.end(),myfunction);

  // print out content:
  std::cout << "myvector contains:";
  print(myvector);

  return 0;
}
