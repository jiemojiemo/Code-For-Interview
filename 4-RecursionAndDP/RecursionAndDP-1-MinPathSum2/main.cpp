#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
	int MinPathSum2(const vector<vector<int>>& m)
	{
		assert(m.size() > 0 && m[0].size() > 0);

		int row = m.size();
		int col = m[0].size();
		int more = std::max(row, col);
		int less = std::min(row, col);
		bool rowmore = row > col;

		vector<int> arr(less, 0);

		arr[0] = m[0][0];

		for (int i = 1; i < less; ++i)
		{
			arr[i] = arr[i - 1] + (rowmore ? m[0][i] : m[i][0]);
		}

		for (int i = 1; i < more; ++i)
		{
			arr[0] = arr[0] + (rowmore ? m[i][0] : m[0][i]);
			for (int j = 1; j < less; ++j)
			{
				arr[j] = std::min(arr[j - 1], arr[j]) + (rowmore ? m[i][j] : m[j][i]);
			}
		}

		return arr[less - 1];
	}
};

int main()
{
	vector<vector<int>> m = { { 1,3,5,9 },{ 8,1,3,4 },{ 5,0,6,1 },{ 8,8,4,0 } };
	Solution ss;
	cout << ss.MinPathSum2(m);

	cin.get();
	return 0;
}