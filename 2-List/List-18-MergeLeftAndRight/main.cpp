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
	Node * MergeLeftAndRight(Node* head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		int len = this->GetLength(head);

		// split list into left part and right part
		Node* leftHead = head;
		Node* righHead = nullptr;
		Node* p = head;
		int count = 0;
		for (;;p = p->next)
		{
			++count;
			if (count == len / 2)
			{
				righHead = p->next;
				p->next = nullptr;
				break;
			}
		}

		// merge left part and right part
		return Merge(leftHead, righHead);

	}
private:
	int GetLength(const Node* head)
	{
		int len = 0;
		auto p = head;
		for (; p != nullptr; p = p->next)
			++len;

		return len;
	}
	Node* Merge(Node* leftHead, Node* rightHead)
	{
		Node dummy(0);
		Node* x = &dummy;

		Node* p = leftHead;
		Node* q = rightHead;

		for (; p != nullptr && q != nullptr;)
		{
			x->next = p;
			p = p->next;
			x = x->next;

			x->next = q;
			q = q->next;
			x = x->next;
		}

		if (q != nullptr)
			x->next = q;

		return dummy.next;
	}

};

int main()
{
	vector<int> v = {1};
	auto head = ConstructList(v);
	Solution ss;
	auto res = ss.MergeLeftAndRight(head);

	PrintList(res);

	cin.get();
	return 0;

}