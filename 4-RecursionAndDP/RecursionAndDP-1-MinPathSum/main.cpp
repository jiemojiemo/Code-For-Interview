#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
	int MinPathSum(const vector<vector<int>>& m)
	{
		assert(m.size() > 0 && m[0].size() > 0);

		int rows = m.size();
		int cols = m[0].size();

		vector<vector<int>> dp(rows, vector<int>(cols));
		dp[0][0] = m[0][0];

		// first cols
		for (int i = 1; i < rows; ++i)
		{
			dp[i][0] = dp[i - 1][0] + m[i][0];
		}

		// first row
		for (int i = 1; i < cols; ++i)
		{
			dp[0][i] = dp[0][i - 1] + m[0][i];
		}


		int leftValue = 0;
		int aboveValue = 0;

		for (int i = 1; i < rows; ++i)
		{
			for (int j = 1; j < cols; ++j)
			{
				aboveValue = dp[i - 1][j];
				leftValue = dp[i][j - 1];

				dp[i][j] = std::min(aboveValue, leftValue) + m[i][j];
			}
		}

		return dp[rows-1][cols-1];
	}
};

int main()
{
	vector<vector<int>> m = { {1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0} };
	Solution ss;
	cout << ss.MinPathSum(m);

	cin.get();
	return 0;
}