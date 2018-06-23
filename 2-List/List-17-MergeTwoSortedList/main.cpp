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
	Node * MergeTwoOrderedList(Node* headA, Node* headB)
	{
		if (headA == nullptr && headB == nullptr)
			return nullptr;
		else if (headA == nullptr)
			return headB;
		else if (headB == nullptr)
			return headA;

		Node dummy(0);
		Node* x = &dummy;

		auto p = headA;
		auto q = headB;

		for (; p != nullptr && q != nullptr;)
		{
			if (p->value < q->value)
			{
				x->next = p;
				x = x->next;
				p = p->next;
			}
			else
			{
				x->next = q;
				x = x->next;
				q = q->next;
			}
		}

		if (p != nullptr)
			x->next = p;
		else if (q != nullptr)
			x->next = q;

		return dummy.next;
	}
};

int main()
{
	vector<int> v1 = {1};
	vector<int> v2 = { 1,3,5,7,9 };
	auto headA = ConstructList(v1);
	auto headB = ConstructList(v2);

	Solution ss;
	auto res = ss.MergeTwoOrderedList(headA, headB);
	PrintList(res);

	cin.get();
	return 0;


}