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


class Solution 
{
public:
	Node * Reverse(Node* head)
	{
		Node* pre = nullptr;
		Node* next = nullptr;

		while (head != nullptr)
		{
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}

		return pre;
	}
};

int main()
{
	vector<int> v = {1,2,3,4,5};
	auto head = ConstructList(v);
	Solution ss;
	auto rhead = ss.Reverse(head);

	PrintList(rhead);

	cin.get();
}