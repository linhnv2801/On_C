// set_symmetric_difference example
#include <iostream>     // std::cout
#include <algorithm>    // std::set_symmetric_difference, std::sort
#include <vector>       // std::vector

namespace algorithm{
	template <class InputIterator1, class InputIterator2, class OutputIterator>
	  OutputIterator set_symmetric_difference (InputIterator1 first1, InputIterator1 last1,
	                                           InputIterator2 first2, InputIterator2 last2,
	                                           OutputIterator result)
	{
	  while (true)
	  {
	    if (first1==last1) return std::copy(first2,last2,result);
	    if (first2==last2) return std::copy(first1,last1,result);
	
	    if (*first1<*first2) { *result=*first1; ++result; ++first1; }
	    else if (*first2<*first1) { *result = *first2; ++result; ++first2; }
	    else { ++first1; ++first2; }
	  }
	}
}

int main () {
  int first[] = {5,10,15,20,25};
  int second[] = {50,40,30,20,10};
  std::vector<int> v(10);                      // 0  0  0  0  0  0  0  0  0  0
  std::vector<int>::iterator it;

  std::sort (first,first+5);     //  5 10 15 20 25
  std::sort (second,second+5);   // 10 20 30 40 50

  it=std::set_symmetric_difference (first, first+5, second, second+5, v.begin());
                                               //  5 15 25 30 40 50  0  0  0  0
  v.resize(it-v.begin());                      //  5 15 25 30 40 50

  std::cout << "The symmetric difference has " << (v.size()) << " elements:\n";
  for (it=v.begin(); it!=v.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

