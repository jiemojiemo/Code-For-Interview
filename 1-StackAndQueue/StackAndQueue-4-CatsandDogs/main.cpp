#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

class Pet {
private:
	string type;

public:
	Pet(string t) :type(t) {}

	string GetType()const { return this->type; }
};

class Cat : public Pet {
public:
	Cat() : Pet("cat") {}
};

class Dog : public Pet {
public:
	Dog() : Pet("dog") {}
};

class PetEnterQueue {
private:
	Pet m_pet;
	unsigned int m_count;

public:
	PetEnterQueue(const Pet& pet, unsigned int count) :m_pet(pet), m_count(count) {}

	unsigned int GetCount()const { return m_count; }
	string GetType()const { return m_pet.GetType(); }
};

class CatsandDogsQueue {
private:
	queue<PetEnterQueue> m_catQ;
	queue<PetEnterQueue> m_dogQ;
	unsigned int m_count;

public:
	CatsandDogsQueue() : m_count(0) {}

	void Add(const Pet& pet)
	{

		if (pet.GetType() == "dog")
			m_dogQ.push(PetEnterQueue(pet, m_count++));
		else
			m_catQ.push(PetEnterQueue(pet, m_count++));
	}

	void PollAll()
	{
		for (; !m_dogQ.empty() || !m_catQ.empty();)
		{
			if (!m_dogQ.empty() && !m_catQ.empty())
			{
				if (m_dogQ.front().GetCount() < m_catQ.front().GetCount())
					m_dogQ.pop();
				else
					m_catQ.pop();
			}
			else if (!m_dogQ.empty())
			{
				m_dogQ.pop();
			}
			else if (!m_catQ.empty())
			{
				m_catQ.pop();
			}
			
		}
	}

	void PollDog()
	{
		for (; !m_dogQ.empty();)
		{
			m_dogQ.pop();
		}
	}

	void PollCat()
	{
		for(;!m_catQ.empty();)
		{ 
			m_catQ.pop();
		}
	}

	bool IsEmpty()const { return m_catQ.empty() && m_dogQ.empty(); }
	bool IsDogEmpty()const { return m_dogQ.empty(); }
	bool IsCatEmpty()const { return m_catQ.empty(); }
};

int main()
{
	CatsandDogsQueue que;

	que.Add(Cat());
	que.Add(Cat());
	que.Add(Dog());
	que.Add(Cat());
	que.Add(Dog());

	cout << que.IsCatEmpty() << endl; // 0
	cout << que.IsDogEmpty() << endl; // 0
	que.PollCat();
	que.PollDog();
	cout << que.IsCatEmpty() << endl; // 1
	cout << que.IsDogEmpty() << endl; // 1

	que.PollAll();	// 1
	cout << que.IsEmpty() << endl;

	cin.get();
	return 0;
}