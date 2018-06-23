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
	Node * PlusTowList(Node* A, Node* B)
	{
		if (B == nullptr)
			return A;
		if (A == nullptr)
			return B;

		stack<Node*> stackA;
		stack<Node*> stackB;

		Node* p = nullptr;
		
		for (p = A; p != nullptr; p = p->next)
			stackA.push(p);

		for (p = B; p != nullptr; p = p->next)
			stackB.push(p);

		int plus = 0;
		Node* q = nullptr;
		Node* pre = nullptr;
		int a = 0;
		int b = 0;
		int c = 0;
		
		for (;plus != 0 || !stackA.empty() || !stackB.empty();)
		{
			if (!stackA.empty())
			{
				a = stackA.top()->value;
				stackA.pop();
			}
			else
				a = 0;

			if (!stackB.empty())
			{
				b = stackB.top()->value;
				stackB.pop();
			}
			else
				b = 0;

			c = a + b + plus;
			plus = c / 10;
			c %= 10;

			p = new Node(c);
			p->next = pre;
			pre = p;

		}

		return p;
	}
};

int main()
{
	vector<int> v1 = { 1,2,3,4,5};
	vector<int> v2 = { 1,2,3,4,5 };

	auto headA = ConstructList(v1);
	auto headB = ConstructList(v2);

	Solution ss;
	auto plus = ss.PlusTowList(headA, headB);

	PrintList(plus);

	cin.get();
	return 0;
}