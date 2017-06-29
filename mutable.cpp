// PROGRAM 1
#include <iostream>
using namespace std;
 
class Test {
public:
  int x;
  mutable int y;
  Test() { x = 4; y = 10; }
};
int main()
{
    const Test t1;
    const volatile Test t2;
    int *p = (int*) &t2.x;
    *p = 100;
    t1.y = 20;
    cout << t1.y << "\t" << t2.x << std::endl;
    return 0;
}
