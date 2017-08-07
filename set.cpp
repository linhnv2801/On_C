// constructing sets
#include <iostream>
#include <set>
#include <algorithm>

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

class classcomp {
	bool reverse;
public:
	classcomp(const bool& revparam = false){
		reverse = revparam;
	}
	bool operator() (const int& lhs, const int& rhs) const
	{if(reverse) return lhs>rhs;
	else return lhs<rhs;}
};

void print(int x){
	std::cout << x << "\t";
}

template <class T>
void printT(T t){
	for_each(t.begin(), t.end(), print);
	std::cout << "\n";
}

int main ()
{
	std::set<int> first;                           // empty set of ints

	int myints[]= {10,20,30,40,50};
	std::set<int> second (myints,myints+5);        // range

	std::set<int> third (second);                  // a copy of second

	std::set<int> fourth (second.begin(), second.end());  // iterator ctor.

	std::set<int,classcomp> fifth;                 // class as Compare

	bool(*fn_pt)(int,int) = fncomp;
	std::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
	sixth.emplace(10),	sixth.emplace(30),	sixth.emplace(20);
	printT(sixth);
	
	typedef std::set<int,classcomp> mytype;
	mytype seventh(classcomp(true));
	seventh.emplace(10),seventh.emplace(30),seventh.emplace(20);
	
	printT(seventh);
	return 0;
}
