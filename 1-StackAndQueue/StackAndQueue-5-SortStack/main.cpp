#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	void SortStack(stack<int>& stackData)
	{
		stack<int> stackHelper;

		for (; !stackData.empty();)
		{
			int x = stackData.top(); stackData.pop();

			if (stackHelper.empty())
				stackHelper.push(x);
			else if (x > stackHelper.top())
			{
				for (; stackHelper.top() < x;)
				{
					stackData.push(stackHelper.top());
					stackHelper.pop();
				}
				stackHelper.push(x);
			}
			else
				stackHelper.push(x);
		}

		// reverse
		for (; !stackHelper.empty();)
		{
			stackData.push(stackHelper.top());
			stackHelper.pop();
		}
	}
};

int main()
{
	vector<int> v = {1,2,0,4,5};
	stack<int> s;
	for (auto item : v)
		s.push(item);

	Solution ss;
	ss.SortStack(s);

	for (; !s.empty();)
	{
		cout << s.top() << endl;
		s.pop();
	}

	cin.get();
	return 0;
}