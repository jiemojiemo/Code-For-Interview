#include <stack>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MyStackSolution2 {
private:
	stack<T> stackData;
	stack<T> stackMin;
public:
	void pop()
	{
		stackData.pop();
		stackMin.pop();
	}
	void push(const T& item)
	{
		stackData.push(item);

		if (stackMin.empty())
		{
			stackMin.push(item);
		}
		else if (item <= stackMin.top())
		{
			stackMin.push(item);
		}
		else
		{
			stackMin.push(stackMin.top());
		}
	}
	T getMin()
	{
		return stackMin.top();
	}
};

int main()
{
	vector<int> v = { 3,4,5,1,2,1 };
	MyStackSolution2<int> myStack;

	// build stack
	for (auto item : v)
	{
		myStack.push(item);
	}

	// test
	cout << myStack.getMin() << endl; // 1
	myStack.pop();

	cout << myStack.getMin() << endl; // 1
	myStack.pop();

	cout << myStack.getMin() << endl; // 1
	myStack.pop();

	cout << myStack.getMin() << endl; // 3
	myStack.pop();

	cout << myStack.getMin() << endl; // 3
	myStack.pop();

	cout << myStack.getMin() << endl; // 3
	myStack.pop();

	cin.get();
	return 0;
}