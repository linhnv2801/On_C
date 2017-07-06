#include <iostream>
#include <typeinfo>
using namespace std;
 
int main(void)
{
    int a1 = 40;
    const int* b1 = &a1;
    char* c1 = (char *)(b1);
    cout << "Type of b1 " << typeid(b1).name() << endl;
//    char *c = const_cast <char *> (b1); // compile error, because b1 & c not same type
    *c1 = 'A';
    a1 = 50;
    *c1 = 'B';
    cout << "Type of b1 " << typeid(b1).name() << endl;
    cout << *b1 << endl;
    cout << *c1 << endl;
    return 0;
}
