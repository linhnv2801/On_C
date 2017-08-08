// random_shuffle example
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

namespace test{
	template <class RandomAccessIterator, class RandomNumberGenerator>
	  void random_shuffle (RandomAccessIterator first, RandomAccessIterator last,
	                       RandomNumberGenerator& gen)
	{
	  typename std::iterator_traits<RandomAccessIterator>::difference_type i, n;
	  n = (last-first);
	  for (i=n-1; i>0; --i) {
	    std::swap (first[i],first[gen(i+1)]);
	  }
	}
}

// random generator function:
int myrandom (int i) { return std::rand()%i;}

int main () {
  std::srand ( unsigned ( std::time(0) ) );
  std::vector<int> myvector;

  // set some values:
  for (int i=1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

  // using built-in random generator:
  std::random_shuffle ( myvector.begin(), myvector.end() );

  // using myrandom:
  test::random_shuffle ( myvector.begin(), myvector.end(), myrandom);

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
