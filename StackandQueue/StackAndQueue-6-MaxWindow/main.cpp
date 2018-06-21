#include <stack>
#include <vector>
#include <iostream>
#include <deque>
#include <cassert>

using namespace std;

class Solution {
public:
	vector<int> GetMaxWindow(const vector<int>& arr, int w)
	{
		assert(arr.size() > 1 && w >= 1);

		vector<int> res;
		deque<int> qmax;

		for (int i = 0; i < arr.size(); ++i)
		{
			for (; !qmax.empty() && arr[i] >= arr[qmax.front()];)
				qmax.pop_back();

			qmax.push_back(i);

			// 是否过期
			if (qmax.front() == i - w)
				qmax.pop_front();

			// 得到结果
			if (i >= w - 1)
				res.push_back(arr[qmax.front()]);
		}

		return res;
	}
};

int main()
{
	vector<int> v = {4,3,5,4,3,3,6,7};
	int w = 3;
	Solution ss;
	auto res = ss.GetMaxWindow(v, w);

	for (auto item : res)
		cout << item << endl;


	cin.get();
	return 0;
}