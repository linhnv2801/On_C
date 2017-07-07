#include <iostream>

using namespace std;

int main()
{
	enum class Color { red, green = 20, blue };
	Color r = Color::blue;
	switch(r)
	{
	    case Color::red  : std::cout << "red\n";   break;
	    case Color::green: std::cout << "green\n"; break;
	    case Color::blue : std::cout << "blue\n";  break;
	}
	// int n = r; // error: no scoped enum to int conversion
	int n = static_cast<int>(r); // OK, n = 21
	return 0;
}
