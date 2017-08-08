// is_partitioned example
#include <iostream>     // std::cout
#include <algorithm>    // std::is_partitioned
#include <array>        // std::array

namespace algorithm{
	template <class InputIterator, class UnaryPredicate>
	  bool is_partitioned (InputIterator first, InputIterator last, UnaryPredicate pred)
	{
	  while (first!=last && pred(*first)) {
	    ++first;
	  }
	  while (first!=last) {
	    if (pred(*first)) return false;
	    ++first;
	  }
	  return true;
	}
}

bool IsOdd (int i) { return (i%2)==1; }

int main () {
  std::array<int,7> foo {1,2,3,4,5,6,7};

  // print contents:
  std::cout << "foo:"; for (int& x:foo) std::cout << ' ' << x;
  if ( algorithm::is_partitioned(foo.begin(),foo.end(),IsOdd) )
    std::cout << " (partitioned)\n";
  else
    std::cout << " (not partitioned)\n";

  // partition array:
  std::partition (foo.begin(),foo.end(),IsOdd);

  // print contents again:
  std::cout << "foo:"; for (int& x:foo) std::cout << ' ' << x;
  if ( algorithm::is_partitioned(foo.begin(),foo.end(),IsOdd) )
    std::cout << " (partitioned)\n";
  else
    std::cout << " (not partitioned)\n";

  return 0;
}
