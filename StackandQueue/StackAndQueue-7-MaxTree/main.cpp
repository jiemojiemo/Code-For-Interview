#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node {
public:
	int value;
	Node* left;
	Node* right;

	Node(int data) :value(data), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	Node * MaxTree(const vector<int>& arr)
	{
		stack<int> leftStack;
		stack<int> rightStack;
		vector<int> leftMaxIndex;
		vector<int> rightMaxIndex;

		// find the first number which larger than arr[i] in left side
		for (int i = 0; i < arr.size(); ++i)
		{
			for (; !leftStack.empty() && arr[i] > arr[leftStack.top()];)
				leftStack.pop();

			if (leftStack.empty())
				leftMaxIndex.push_back(-1);
			else
				leftMaxIndex.push_back(leftStack.top());

			leftStack.push(i);
		}

		// find the first number which larger than arr[i] in right side
		for (int i = arr.size() - 1; i >= 0; --i)
		{
			for (; !rightStack.empty() && arr[i] > arr[rightStack.top()];)
				rightStack.pop();

			if (rightStack.empty())
				rightMaxIndex.push_back(-1);
			else
				rightMaxIndex.push_back(rightStack.top());

			rightStack.push(i);
		}
		std::reverse(rightMaxIndex.begin(), rightMaxIndex.end());

		// build the max tree
		vector<Node*> nodeVec;
		for (auto item : arr)
			nodeVec.push_back(new Node(item));

		Node dummy(0);
		for (int i = 0; i < nodeVec.size(); ++i)
		{
			auto leftIndex = leftMaxIndex[i];
			auto rightIndex = rightMaxIndex[i];
			Node* parent = nullptr;

			if (leftIndex == -1 && rightIndex == -1)
			{
				dummy.left = nodeVec[i];
				continue;
			}
			else if (leftIndex == -1)
				parent = nodeVec[rightIndex];
			else if (rightIndex == -1)
				parent = nodeVec[leftIndex];
			else if (arr[leftIndex] <= arr[rightIndex])
				parent = nodeVec[leftIndex];
			else if (arr[leftIndex] > arr[rightIndex])
				parent = nodeVec[rightIndex];

			if (parent->left == nullptr)
				parent->left = nodeVec[i];
			else
				parent->right = nodeVec[i];

		}

		return dummy.left;

	}
};

int main()
{
	vector<int> v = {3,4,5,1,2};
	Solution ss;
	auto maxTree = ss.MaxTree(v);

	cin.get();
	return 0;
}