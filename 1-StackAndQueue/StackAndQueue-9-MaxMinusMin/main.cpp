#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int NumberOfSubArray(const vector<int>& arr, int num)
	{
		int i = 0;
		int j = 0;
		deque<int> qmax;
		deque<int> qmin;

		int res = 0;

		for (j = 0; j < arr.size(); ++j)
		{
			// push the maximum to the qmax
			for (; !qmax.empty() && arr[j] >= arr[qmax.front()];)
				qmax.pop_back();
			qmax.push_back(j);

			// push the minimum to the qmin
			for (; !qmin.empty() && arr[j] <= arr[qmin.front()];)
				qmin.pop_back();
			qmin.push_back(j);

			// if max(arr[i..j]) - min(arr[i..j]) > num
			if (arr[qmax.front()] - arr[qmin.front()] > num)
			{
				res += j - i;

				if (qmax.front() == i)
					qmax.pop_front();
				if (qmin.front() == i)
					qmin.pop_front();

				// update i
				++i;
			}
		}

		res += j - i;

		return res;
	}
};

int main()
{
	vector<int> v = { 1,2,3,4,2 };
	int num = 2;

	Solution ss;
	auto res = ss.NumberOfSubArray(v, num);

	cout << res << endl;

	cin.get();
	return 0;
}