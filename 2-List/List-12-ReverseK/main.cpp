#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
	Node * next;
	int value;

	Node(int v) : value(v), next(nullptr) {}
};

Node* ConstructList(const vector<int>& arr)
{
	Node* head = nullptr;
	Node* p = nullptr;

	for (auto item : arr)
	{
		Node* node = new Node(item);

		if (head == nullptr)
		{
			head = node;
			p = head;
		}
		else
		{
			p->next = node;
			p = p->next;
		}

	}
	return head;
}

void PrintList(Node* head)
{
	auto p = head;
	for (; p != nullptr; p = p->next)
		cout << p->value << ",";
	cout << endl;
}

class Solution {
public:
	Node * ReverseK(Node* head, int k)
	{
		if (k < 2)
			return head;

		if (head == nullptr || head->next == nullptr)
			return head;

		Node dummy(0);
		Node* pre = &dummy;
		Node* p = head;
		Node* q = nullptr;
		stack<Node*> nodeStack;
		int count = 0;
		for (; p != nullptr;)
		{
			++count;
			nodeStack.push(p);
			p = p->next;
			if (count % k == 0)
			{
				for (; !nodeStack.empty();)
				{
					q = nodeStack.top(); nodeStack.pop();
					pre->next = q;
					pre = q;
				}
			}
		}
		for (; !nodeStack.empty();)
		{
			p = nodeStack.top();
			nodeStack.pop();
		}

		pre->next = p;

		return dummy.next;
	}
};

int main()
{
	vector<int> v = {1,2};
	auto head = ConstructList(v);
	Solution ss;
	auto res = ss.ReverseK(head, 3);
	PrintList(res);
	cin.get();
	
}