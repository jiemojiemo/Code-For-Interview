#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	Node * next;
	int value;

	Node(int v) : value(v), next(nullptr) {}
};

Node* ConstructCycleList(const vector<int>& arr)
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
	p->next = head;
	return head;
}

void PrintCycleList(Node* head)
{
	auto p = head;
	for (;;)
	{
		cout << p->value << ",";
		p = p->next;
		if (p == head)
			break;
	}
	cout << endl;
}

class Solution
{
public:
	Node* JosephusKill(Node* head, int m)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		int count = 1; // start from 1
		Node* pre = nullptr;
		Node* p = head;

		while (p != pre)
		{
			// move p
			pre = p;
			p = p->next;
			++count;

			if (count % m == 0)
			{
				pre->next = p->next;
				cout << p->value << endl;
				delete p;
				// move p
				p = pre->next;
				count = 1; // reset count;
			}
		}

		return p;
	}
};

int main()
{
	vector<int> v = {1,2,3,4,5,6,7};
	int m = 3;
	auto head = ConstructCycleList(v);
	PrintCycleList(head);

	Solution ss;
	auto theLastOne = ss.JosephusKill(head, m);
	cout << theLastOne->value << endl;

	cin.get();
	return 0;
}

