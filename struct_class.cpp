#include <stdio.h>

class Base {
public:
	int x;
};

struct Derived_s : Base { }; // is equilalent to struct Derived : public Base {}
class Derived_c : Base { }; // is equilalent to struct Derived : public Base {}

int main()
{
	Derived_s d;
	Derived_c c;
	d.x = 20; // works fine becuase inheritance is public
//	c.x = 20; // compiler error becuase inheritance is private
	
	printf("Reference : http://www.geeksforgeeks.org/g-fact-76/");
	return 0;
}
