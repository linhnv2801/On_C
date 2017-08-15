// set_union example
#include <iostream>     // std::cout
#include <algorithm>    // std::set_union, std::sort
#include <vector>       // std::vector

namespace algorithm{
	template <class InputIterator1, class InputIterator2, class OutputIterator>
	  OutputIterator set_union (InputIterator1 first1, InputIterator1 last1,
	                            InputIterator2 first2, InputIterator2 last2,
	                            OutputIterator result)
	{
	  while (true)
	  {
	    if (first1==last1) return std::copy(first2,last2,result);
	    if (first2==last2) return std::copy(first1,last1,result);
	
	    if (*first1<*first2) { *result = *first1; ++first1; }
	    else if (*first2<*first1) { *result = *first2; ++first2; }
	    else { *result = *first1; ++first1; ++first2; }
	    ++result;
	  }
	}
}

int main () {
  int first[] = {5,10,15,20,25,25,40,40,45,65,75};
  int second[] = {5,5,50,40,30,20,25,25,25,10};
  std::vector<int> v(sizeof(first)/sizeof(int) + sizeof(second)/sizeof(int));                      // 0  0  0  0  0  0  0  0  0  0
  std::vector<int>::iterator it;

  std::sort (first, first + sizeof(first)/sizeof(int));     //  5 10 15 20 25
  std::sort (second,second+ sizeof(second)/sizeof(int));   // 10 20 30 40 50

  it=std::set_union (first, first+ sizeof(first)/sizeof(int), second, second+sizeof(second)/sizeof(int), v.begin());
                                               // 5 10 15 20 25 30 40 50  0  0
  v.resize(it-v.begin());                      // 5 10 15 20 25 30 40 50

  std::cout << "The union has " << (v.size()) << " elements:\n";
  for (it=v.begin(); it!=v.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
