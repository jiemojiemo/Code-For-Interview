#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int GetMaxArea(const vector<vector<int>>& m)
	{
		int rows = m.size();
		int cols = m[0].size();

		vector<int> height(cols, 0);
		stack<int> mStack;
		vector<int> toLeftMaxIndex(cols,-1);
		vector<int> toRightMaxIndex(cols,-1);
		int maxArea = -1;

		for (int i = 0; i < rows; ++i)
		{
			// calc height
			for (int j = 0; j < cols; ++j)
				height[j] = m[i][j] == 0 ? 0 : height[j] + 1;

			// left index
			for (int j = 0; j < cols; ++j)
			{
				for (; !mStack.empty() && height[j] <= height[mStack.top()];)
					mStack.pop();

				if (mStack.empty())
					toLeftMaxIndex[j] = 0;
				else
					toLeftMaxIndex[j] = mStack.top() + 1;

				mStack.push(j);
			}
			// clear stack
			for (; !mStack.empty();) mStack.pop();

			// right index
			for (int j = cols-1; j >= 0; --j)
			{
				for (; !mStack.empty() && height[j] <= height[mStack.top()];)
					mStack.pop();

				if (mStack.empty())
					toRightMaxIndex[j] = cols - 1;
				else
					toRightMaxIndex[j] = mStack.top() - 1;

				mStack.push(j);
			}
			// clear stack
			for (; !mStack.empty();) mStack.pop();

			// calculate area and save the maximun

			for (int j = 0; j < cols; ++j)
			{
				int area = (toRightMaxIndex[j] - toLeftMaxIndex[j] + 1)*height[j];
				if (area > maxArea)
					maxArea = area;
			}
		}

		return maxArea;
	}
private:
	stack<int> m_stack;
	
};

int main()
{
	//vector<vector<int>> m = { {1,0,1,1},{1,1,1,1},{1,1,1,0} };
	//vector<vector<int>> m = { {0,0,0,0}, { 1,1,1,1 },{ 1,1,1,1 },{ 0,0,0,0 } };
	vector<vector<int>> m = { { 1,0,1,0 },{ 0,1,0,1 },{ 1,0,1,0 },{ 0,1,0,1 } };
	Solution ss;
	auto maxArea = ss.GetMaxArea(m);
	cout << maxArea << endl;

	cin.get();
	return 0;
}