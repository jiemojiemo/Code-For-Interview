#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	Node * next;
	int value;

	Node(int v) : value(v),next(nullptr) {}
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

class Solution 
{
public:
	Node * DeleteK(Node* head, int k)
	{
		//assert(k > 0);

		Node dummy(0);
		dummy.next = head;

		Node* preq = nullptr;
		Node* q = nullptr;
		Node* p = head;

		int count = 0;

		for (; p != nullptr;p = p->next)
		{
			++count;

			if (count == k)
			{
				preq = &dummy;
				q = preq->next;
			}
			else if (count > k)
			{
				preq = preq->next;
				q = preq->next;
			}
		}

		if (count < k)
			return head;
		else
		{
			preq->next = q->next;
			delete q;

			return head;
		}
	}

};

void PrintList(Node* head)
{
	auto p = head;
	for (; p != nullptr; p = p->next)
		cout << p->value << ",";
	cout << endl;
}

int main()
{
	vector<int> v = {1,2,3,4,2};
	auto head = ConstructList(v);
	int k = 4;
	PrintList(head);
	Solution ss;
	auto afterDelete = ss.DeleteK(head, k);
	
	PrintList(afterDelete);

	cin.get();
	return 0;
}