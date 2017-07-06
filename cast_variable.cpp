#include <iostream>
using namespace std;
 
int main(void)
{
    const int val = 10;
    int *ptr = const_cast <int *>(&val);
    *ptr += 10;
    cout << *ptr << endl;
    cout << "val = " << val << endl;
    return 0;
}
