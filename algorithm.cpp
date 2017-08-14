// includes algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::includes, std::sort

namespace algorithm {
	template <class InputIterator1, class InputIterator2>
	  bool includes (InputIterator1 first1, InputIterator1 last1,
	                 InputIterator2 first2, InputIterator2 last2)
	{
	  while (first2!=last2) {
	    if ( (first1==last1) || (*first2<*first1) ) return false;
	    if (!(*first1<*first2)) ++first2;
	    ++first1;
	  }
	  return true;
	}
}

bool myfunction (int i, int j) { return i>j; }

int main () {
  int container[] = {5,10,15,20,25,30,35,40,45,50};
  int continent[] = {40,30,25,10};

  std::sort (container,container+10, myfunction);
  std::sort (continent,continent+4, myfunction);

  // using default comparison:
  if ( std::includes(container,container+10,continent,continent+4) )
    std::cout << "container includes continent!\n";

  // using myfunction as comp:
  if ( std::includes(container,container+10,continent,continent+4, myfunction) )
    std::cout << "container includes continent!\n";

  return 0;
}
