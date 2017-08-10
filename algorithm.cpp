// partition_point example
#include <iostream>     // std::cout
#include <algorithm>    // std::partition, std::partition_point
#include <vector>       // std::vector

namespace algorithm{
	template <class ForwardIterator, class UnaryPredicate>
	  ForwardIterator partition_point (ForwardIterator first, ForwardIterator last,
	                                   UnaryPredicate pred)
	{
	  auto n = distance(first,last);
	  while (n>0)
	  {
	    ForwardIterator it = first;
	    auto step = n/2;
	    std::advance (it,step);
	    if (pred(*it)) { first=++it; n-=step+1; }
	    else n=step;
	  }
	  return first;
	}
}

bool IsOdd (int i) { return (i%2)==1; }

int main () {
  std::vector<int> foo {1,2,3,4,5,6,7,8,9};
  std::vector<int> odd;

  std::partition (foo.begin(),foo.end(),IsOdd);

  auto it = std::partition_point(foo.begin(),foo.end(),IsOdd);
  odd.assign (foo.begin(),it);

  // print contents of odd:
  std::cout << "odd:";
  for (int& x:odd) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
