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
	Node * DeleteRepeat(Node* head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		unordered_set<int> hSet;

		Node dummy(0);
		dummy.next = head;
		Node* pre = &dummy;
		Node* p = head;

		for (; p != nullptr;)
		{
			// delete element
			if (hSet.find(p->value) != hSet.end())
			{
				pre->next = p->next;
				delete p;
				p = pre->next;
			}
			else
			{
				hSet.insert(p->value);
				pre = p;
				p = p->next;
			}
		}

		return dummy.next;
	}
};

int main()
{
	vector<int> v = {1,1,2,3,4,4,5,6,6};
	auto head = ConstructList(v);
	Solution ss;
	auto res = ss.DeleteRepeat(head);
	PrintList(res);

	cin.get();
	return 0;
}