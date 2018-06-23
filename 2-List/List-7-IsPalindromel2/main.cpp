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

class Solution
{
public:
	bool IsPalindromel2(Node* head)
	{
		if (head == nullptr || head->next == nullptr)
			return true;

		int len = 0;
		Node* p = head;

		for (; p != nullptr; p = p->next)
			++len;
		

		int middle = len / 2;
		stack<Node*> nodeStack;
		p = head;
		for (int i = 0; i < middle; ++i)
		{
			nodeStack.push(p);
			p = p->next;
		}

		// compare
		if (len % 2 == 1)
			p = p->next;
		for (; p != nullptr; p = p->next)
		{
			if (p->value != nodeStack.top()->value)
				return false;
			nodeStack.pop();
		}

		return true;

	}
};

int main()
{
	vector<int> v = { 1,2,3,2,1 };
	auto head = ConstructList(v);
	Solution ss;
	bool isPali = ss.IsPalindromel2(head);
	cout << isPali << endl;
	cin.get();

}