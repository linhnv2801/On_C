// is_sorted example
#include <iostream>     // std::cout
#include <algorithm>    // std::is_sorted, std::prev_permutation
#include <array>        // std::array

namespace algorithm{
	template <class ForwardIterator>
	  bool is_sorted (ForwardIterator first, ForwardIterator last)
	{
	  if (first==last) return true;
	  ForwardIterator next = first;
	  while (++next!=last) {
	    if (*next<*first)     // or, if (comp(*next,*first)) for version (2)
	      return false;
	    ++first;
	  }
	  return true;
	}
}

int main () {
  std::array<int,4> foo {2,4,1,3};

  do {
    // try a new permutation:
    std::prev_permutation(foo.begin(),foo.end());

    // print range:
    std::cout << "foo:";
    for (int& x:foo) std::cout << ' ' << x;
    std::cout << '\n';

  } while (!std::is_sorted(foo.begin(),foo.end()));

  std::cout << "the range is sorted!\n";

  return 0;
}
