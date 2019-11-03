#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
class myLess {
public:
	bool operator()(int &t1, int &t2){
		return t1 < t2;
	}
};
class myBig {
public:
	bool operator()(int &t1, int &t2) {
		return t1 > t2;
	}
};

void queueTest()
{
	

	priority_queue<int, deque<int>, greater<int>> smallQueue;
	priority_queue<int> bigQueue;
	std::priority_queue<int, std::vector<int>, greater<int>> pq;

	
	smallQueue.push(3);
	smallQueue.push(1);
	smallQueue.push(2);
	smallQueue.push(5);
	smallQueue.push(4);

	while (!smallQueue.empty())
	{
		cout << smallQueue.top()<<" ";
		smallQueue.pop();
	}
	cout << endl;

	bigQueue.push(3);
	bigQueue.push(1);
	bigQueue.push(2);
	bigQueue.push(5);
	bigQueue.push(4);

	while (!bigQueue.empty())
	{
		cout << bigQueue.top() << " ";
		bigQueue.pop();
	}
	cout << endl;

	int t = 0;
	


}
