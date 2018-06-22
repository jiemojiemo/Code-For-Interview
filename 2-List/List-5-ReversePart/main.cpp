#include <iostream>
#include <vector>

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
	Node* ReversePart(Node* head, int from, int to)
	{
		Node* fPre = nullptr;
		Node* tPos = nullptr;
		Node* p = head;
		int len = 0;

		while (p != nullptr)
		{
			++len;

			fPre = (len == from - 1) ? p : fPre;
			tPos = (len == to + 1) ? p : tPos;

			p = p->next;
		}

		if (from > to || from < 1 || to > len)
			return head;

		Node* pre = nullptr;
		Node* next = nullptr;

		pre = (fPre == nullptr) ? head : fPre->next;
		p = pre->next;

		while (p != tPos)
		{
			next = p->next;
			p->next = pre;
			pre = p;
			p = next;
		}

		if (fPre == nullptr)
		{
			head->next = p;
			return pre;
		}
		else
		{
			fPre->next->next = p;
			fPre->next = pre;
			return head;
		}

	}
};

int main()
{
	vector<int> v = { 1,2,3,4,5 };
	auto head = ConstructList(v);
	Solution ss;
	int from = 2;
	int to = 4;
	auto rhead = ss.ReversePart(head, from, to);

	PrintList(rhead);

	cin.get();
}