// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j)
{
    return (i<j);
}

struct myclass
{
    bool operator() (int i,int j)
    {
        return (i<j);
    }
} myobject;

void print(int x)
{
    std::cout << x << "\t";
}

template <class T>
void printT(T t){
	for_each(t.begin(), t.end(), print);
	std::cout << "\n";
}

int main ()
{
    int myints[] = {32,71,12,45,26,80,53,33};
    std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

    // using default comparison (operator <):
    std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

    // using function as comp
    std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

    // using object as comp
    std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

    // print out content:
    std::cout << "myvector contains:";
    printT(myvector);

    return 0;
}
