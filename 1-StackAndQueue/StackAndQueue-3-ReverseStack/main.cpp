#include <stack>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
T getAndRemoveLastElement(stack<T>& s)
{
	auto result = s.top(); s.pop();

	if (s.empty())
		return result;
	else
	{
		auto last = getAndRemoveLastElement(s);
		s.push(result);
		return last;
	}
}

template <typename T>
void reverse(stack<T>& s)
{
	if (s.empty())
		return;
	else
	{
		auto last = getAndRemoveLastElement(s);
		reverse(s);
		s.push(last);
	}
}

int main()
{
	vector<int> v = { 0,1,2,3 };
	stack<int> s;
	for (auto item : v)
		s.push(item);

	reverse(s);

	for (; !s.empty();)
	{
		cout << s.top() << endl;
		s.pop();
	}

	cin.get();
	return 0;
}