// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

class mycomparison
{
	bool reverse;
public:
	mycomparison(const bool& revparam=false)
	{reverse=revparam;}
	bool operator() (const int& lhs, const int&rhs) const
	{
		if (reverse) return (lhs>rhs);
		else return (lhs<rhs);
	}
};

void print(int x){
	std::cout << x << "\t";
}

template <class T>
void print(T t){
	while(!t.empty()){
		print(t.top());
		t.pop();
	}
	std::cout << "\n";
}

int main ()
{
	int myints[]= {10,60,50,20};

	std::priority_queue<int> first;
	std::priority_queue<int> second (myints,myints+4);
	std::priority_queue<int, std::vector<int>, std::greater<int> >
		third (myints,myints+4);
	// using mycomparison:
	typedef std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;

	mypq_type fourth;                       // less-than comparison
	mypq_type fifth (mycomparison(true));   // greater-than comparison
	
	fourth.push(30), fourth.push(40), fourth.push(50);
	fifth.push(30), fifth.push(40), fifth.push(50);
	
	print(fifth);

	return 0;
}
