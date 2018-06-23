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

class Solution{
public:
	Node * SmallEqualBig(Node* head, int pivot)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		queue<Node*> smallQue;
		queue<Node*> equalQue;
		queue<Node*> bigQue;

		auto p = head;
		for (; p != nullptr; p = p->next)
		{
			if (p->value < pivot)
				smallQue.push(p);
			else if (p->value == pivot)
				equalQue.push(p);
			else
				bigQue.push(p);
		}

		Node dummy(0);
		p = &dummy;
		for (; !smallQue.empty();)
		{
			p->next = smallQue.front(); smallQue.pop();
			p = p->next;
		}
		for (; !equalQue.empty();)
		{
			p->next = equalQue.front(); equalQue.pop();
			p = p->next;
		}
		for (; !bigQue.empty();)
		{
			p->next = bigQue.front(); bigQue.pop();
			p = p->next;
		}
		p->next = nullptr;
		return dummy.next;
		
	}
};

int main()
{
	vector<int> arr = {11,2,3,4,5,33,5,7,5,5};
	int pivot = 5;

	auto head = ConstructList(arr);

	Solution ss;
	auto res = ss.SmallEqualBig(head, pivot);

	PrintList(res);

	cin.get();
	return 0;
}
