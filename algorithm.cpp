// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j)
{
    return (i<j);
}

class classcomp
{
private:
	bool reverse;
public:
	classcomp(const bool& revparam = false){
		reverse = revparam;
	}		
    bool operator() (int i,int j) const
    {
    	if(reverse) return (i>j);
		else return (i<j);
    }
};

template <typename T>
void print0(T x)
{
    std::cout << x << "\t";
}

template <typename T>
void print(const std::vector<T> t){
	for_each(t.begin(), t.end(), print0);
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
    std::sort (myvector.begin(), myvector.end(), classcomp(true));     //(12 26 32 33 45 53 71 80)

    // print out content:
    std::cout << "myvector contains: ";
    print(myvector);
    
    return 0;
}
