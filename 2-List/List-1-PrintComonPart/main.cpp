#include <list>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	Node * next;
	int value;

	Node(int v) : value(v) {}
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

class Solution {
public:
	void PrintCommonPart(Node* headA, Node* headB)
	{
		auto p = headA;
		auto q = headB;

		for (; p != nullptr && q != nullptr;)
		{
			if (p->value < q->value)
				p = p->next;
			else if (q->value < p->value)
				q = q->next;
			else if (p->value == q->value)
			{
				cout << p->value << ",";
				p = p->next;
				q = q->next;
			}
		}
	}
};

int main()
{
	vector<int> v1 = {6,7,8,9,10,11,12,20,21};
	auto headA = ConstructList(v1);

	vector<int> v2 = {1,2,7,8,9,10,15,16,20,21};
	auto headB = ConstructList(v2);

	Solution ss;
	ss.PrintCommonPart(headA, headB);

	cin.get();
	return 0;
}