#include <iostream>
#include <vector>
#include <queue>

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
	Node * SmallEqualBig(Node* head, int pivot)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		Node smallDummy(0);
		Node* smallP = &smallDummy;

		Node equalDummy(0);
		Node* equalP = &equalDummy;

		Node bigDummy(0);
		Node* bigP = &bigDummy;

		Node* p = head;

		for (; p != nullptr; p = p->next)
		{
			if (p->value < pivot)
			{
				smallP->next = p;
				smallP = smallP->next;
			}
			else if (p->value == pivot)
			{
				equalP->next = p;
				equalP = equalP->next;
			}
			else
			{
				bigP->next = p;
				bigP = bigP->next;
			}
		}
		bigP->next = nullptr;

		if (equalDummy.next != nullptr)
		{
			smallP->next = equalDummy.next;
			equalP->next = bigDummy.next;
		}
		else if (bigDummy.next != nullptr)
		{
			smallP->next = bigDummy.next;
		}

		return smallDummy.next;

	}
};

int main()
{
	vector<int> v = { 1,2,3,2,1 };
	auto head = ConstructList(v);
	Solution ss;
	auto res = ss.SmallEqualBig(head, 1);
	PrintList(res);

	cin.get();
	return 0;
}