// initialization of variables

#include <iostream>
using namespace std;

int main ()
{
  int a=5;               // initial value: 5
  int b(3);              // initial value: 3
  int c{2};              // initial value: 2
  int result;            // initial value undetermined
  int d = a;
  int z = int();
  int x(a);
  int y{a};
  cout << "d = " << d << "\n";
  cout << "z = " << z << "\n";
  cout << "x = " << x << "\n";
  cout << "y = " << y << "\n";

  a = a + b;
  result = a - c;
  cout << result;

  return 0;
}
