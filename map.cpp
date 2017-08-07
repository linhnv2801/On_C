// constructing maps
#include <iostream>
#include <map>
#include <algorithm>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

class classcomp {
	bool reverse;
public:	
	classcomp(const bool& revparam = false){
		reverse = revparam;
	}	
	bool operator() (const char& lhs, const char& rhs) const
	{if(reverse) return lhs>rhs;else return lhs<rhs;}
};

template <class T>
void print(T t){
	for(typename T::iterator it=t.begin(); it!=t.end();++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n";
}


int main ()
{
	std::map<char,int> first;

	first['a']=10,first['b']=30,first['c']=50,first['d']=70;

	std::map<char,int> second (first.begin(),first.end());
	print(second);

	std::map<char,int> third (second);

	std::map<char,int,classcomp> fourth;                 // class as Compare

	bool(*fn_pt)(char,char) = fncomp;
	std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	
	typedef std::map<char,int,classcomp> mytype;
	mytype sixth(true);
	sixth['a']=10, sixth['b']=30, sixth['c']=50, sixth['d']=70;
	print(sixth);
	
	return 0;
}
