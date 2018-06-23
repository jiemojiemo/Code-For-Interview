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

class Solution {
public:
	Node* InsertCycleList(Node* head, int m)
	{
		Node* newNode = new Node(m);

		if (head == nullptr)
		{
			newNode->next = newNode;
			return newNode;
		}


		Node* last = nullptr;
		Node* p = head;

		// find the last element
		for (; p->next != head;)
			p = p->next;
		last = p;

		Node* pre = last;
		for ( p = head; p->next != head;)
		{
			// find and insert
			if (p->value > newNode->value)
			{
				pre->next = newNode;
				newNode->next = p;

				break;
			}
			else
			{
				pre = p;
				p = p->next;
			}
		}
		// if m is the smallest number
		if (p == head)
			return newNode;
		// if m is the biggest number, 
		else if (p->next == head)
		{
			p->next = newNode;
			newNode->next = head;
		}
		else
			return head;
		
	}
};

int main()
{
	vector<int> v = {1,2,3,4,5};
	int m = 1;
	auto head = ConstructCycleList(v);

	Solution ss;
	auto res = ss.InsertCycleList(head, m);
	PrintCycleList(res);

	cin.get();
	return 0;
}