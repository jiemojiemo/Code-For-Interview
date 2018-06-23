#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
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
	Node * SelectSort(Node* head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		Node dummy(0);
		
		Node* q = head;
		dummy.next = q;
		Node* p = q->next;	// p is the head of unsorted part
		q->next = nullptr;	// q is the head of sorted part

		Node* next = nullptr;
		Node* pre = nullptr;

		for (; p != nullptr;)
		{
			next = p->next;

			pre = &dummy;
			q = pre->next;
			for (; q != nullptr;)
			{
				// insert into sorted
				if (q->value > p->value)
				{
					p->next = q;
					pre->next = p;
					break;
				}
				else
				{
					pre = q;
					q = q->next;
				}
			}
			if (q == nullptr)
			{
				pre->next = p;
				p->next = nullptr;
			}

			// update p
			p = next;

		}

		return dummy.next;

	}
};

int main()
{
	vector<int> v = {4,7,1,2,5,8,0,-2,1,2,3,19};
	auto head = ConstructList(v);
	Solution ss;
	auto res = ss.SelectSort(head);
	PrintList(res);

	cin.get();
	return 0;
}