#include<iostream>
using namespace std;
 
class Test {
    int value;
public:
    Test(int v = 0) {value = v;}
     
    // We get compiler error if we add a line like "value = 100;"
    // in this function.
    int getValue() const {return value;}  
    int* const get() {
    	return &value;
	}
};
 
int main() {
    Test t(20);
    cout<<t.getValue() << endl;
    *t.get() = 4;
    cout<<t.getValue() << endl;
    
    return 0;
}
