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
	bool IsPalindromel(Node* head)
	{
		if (head == nullptr && head->next == nullptr)
			return true;

		stack<Node*> nodeStack;
		Node* p = head;
		for (; p != nullptr; p=p->next)
		{
			nodeStack.push(p);
		}

		// compare
		p = head;
		for (; p != nullptr;)
		{
			if (p->value != nodeStack.top()->value)
				return false;

			p = p->next;
			nodeStack.pop();
		}

		return true;
		
	}
};

int main()
{
	vector<int> v = {1};
	auto head = ConstructList(v);
	Solution ss;
	bool isPali = ss.IsPalindromel(head);
	cout << isPali << endl;
	cin.get();


}