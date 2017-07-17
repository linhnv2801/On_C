// copy_backward example
#include <iostream> // std::cout
#include <algorithm> // std::copy_backward
#include <vector> // std::vector

//template <class T>
void print(float i){
	std::cout << i << "\t";
}

int main()
{
    std::vector<float> myvector;

    // set some values:
    for (float i = 1; i <= 5; i++)
        myvector.push_back(i * 10); // myvector: 10 20 30 40 50
    
    std::cout << myvector.size() << "\n";
    for_each(myvector.begin(),myvector.end(),print);
    std::cout << "\n";
    
    std::cout << *(myvector.begin()) << "\n";
    std::cout << *(--std::end(myvector)) << "\n";

    myvector.resize(myvector.size() + 3); // allocate space for 3 more elements

    std::copy_backward(myvector.begin(), myvector.begin() + 8, myvector.end());

    std::cout << "myvector contains:";
    for (std::vector<float>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}
