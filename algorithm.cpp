// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

class comp{
	bool reverse;
public:
	comp(bool param){
		reverse = param;
	}	
	bool operator()(const int& lhs, const int& rhs) const{
		if(reverse) return (lhs > rhs);
		else return (lhs < rhs);
	}
};

int main () {
  int myints[] = {10,20,30,5,15,100};
  std::vector<int> v(myints,myints+sizeof(myints)/sizeof(int));

  std::make_heap (v.begin(),v.end(),comp(true));
  std::cout << "initial max heap   : " << v.front() <<"\t"<< v.back()<< '\n';

  std::pop_heap (v.begin(),v.end()); v.pop_back();
  std::cout << "max heap after pop : " << v.front() << '\n';

  v.push_back(99); std::push_heap (v.begin(),v.end());
  std::cout << "max heap after push: " << v.front() << '\n';

  std::sort_heap (v.begin(),v.end());

  std::cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
    std::cout << ' ' << v[i];

  std::cout << '\n';

  return 0;
}
