#include <stack>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class TwoStackQueue {
private:
	stack<T> stackPush;
	stack<T> stackPop;

public:
	void add(const T& item)
	{
		stackPush.push(item);
	}
	void poll()
	{
		// push all elements in stackPush to stackPop
		if (stackPop.empty())
		{
			for (; !stackPush.empty();)
			{
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
		return stackPop.pop();
	}

	T peak()
	{
		// push all elements in stackPush to stackPop
		if (stackPop.empty())
		{
			for (; !stackPush.empty();)
			{
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}

		return stackPop.top();
	}
};

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7 };
	TwoStackQueue<int> myStack;
	for (auto item : v)
	{
		myStack.add(item);
	}

	cout << myStack.peak() << endl; // 1
	myStack.poll();

	cout << myStack.peak() << endl; // 2 
	myStack.poll();

	cout << myStack.peak() << endl; // 3
	myStack.poll();

	cout << myStack.peak() << endl; // 4
	myStack.poll();

	cout << myStack.peak() << endl; // 5
	myStack.poll();

	cin.get();
	return 0;
}