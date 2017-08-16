// set_difference example
#include <iostream>     // std::cout
#include <algorithm>    // std::set_difference, std::sort
#include <vector>       // std::vector

namespace algorithm{
	template <class InputIterator1, class InputIterator2, class OutputIterator>
	  OutputIterator set_difference (InputIterator1 first1, InputIterator1 last1,
	                                 InputIterator2 first2, InputIterator2 last2,
	                                 OutputIterator result)
	{
	  while (first1!=last1 && first2!=last2)
	  {
	    if (*first1<*first2) { *result = *first1; ++result; ++first1; }
	    else if (*first2<*first1) ++first2;
	    else { ++first1; ++first2; }
	  }
	  return std::copy(first1,last1,result);
	}
}

int main () {
  int first[] = {5,10,15,20,25,35};
  int second[] = {50,40,30,20,10};
  std::vector<int> v(sizeof(first)/sizeof(int) + sizeof(second)/sizeof(int));                      // 0  0  0  0  0  0  0  0  0  0
  std::vector<int>::iterator it;

  std::sort (first,first+sizeof(first)/sizeof(int));     //  5 10 15 20 25
  std::sort (second,second+sizeof(second)/sizeof(int));   // 10 20 30 40 50

  it=std::set_difference (first, first+sizeof(first)/sizeof(int), second, second+sizeof(second)/sizeof(int), v.begin());
                                               //  5 15 25  0  0  0  0  0  0  0
  v.resize(it-v.begin());                      //  5 15 25

  std::cout << "The difference has " << (v.size()) << " elements:\n";
  for (it=v.begin(); it!=v.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
