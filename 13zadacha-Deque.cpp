#include <iostream>
using namespace std;

class DequeEmptyException
{
public:
	DequeEmptyException()
	{
		cout << "Deque empty" << endl;
	}
};


class Node
{
public:
	int data;
	Node* next;
	Node* prev;
};

class Deque
{
private:
	Node* front;
	Node* rear;
	int count;

public:
	Deque()
	{
		front = NULL;
		rear = NULL;
		count = 0;
	}

	void InsertFront(int element)
	{

		Node* tmp = new Node();
		tmp->data = element;
		tmp->next = NULL;
		tmp->prev = NULL;

		if (isEmpty()) {

			front = rear = tmp;
		}
		else {

			tmp->next = front;
			front->prev = tmp;
			front = tmp;
		}

		count++;
	}

	int RemoveFront()
	{
		if (isEmpty()) {
			throw new DequeEmptyException();
		}


		int ret = front->data;


		Node* tmp = front;
		if (front->next != NULL)
		{
			front = front->next;
			front->prev = NULL;
		}
		else
		{
			front = NULL;
		}
		count--;
		delete tmp;

		return ret;
	}

	void InsertBack(int element)
	{

		Node* tmp = new Node();
		tmp->data = element;
		tmp->next = NULL;
		tmp->prev = NULL;

		if (isEmpty()) {

			front = rear = tmp;
		}
		else {

			rear->next = tmp;
			tmp->prev = rear;
			rear = tmp;
		}

		count++;
	}

	int RemoveBack()
	{
		if (isEmpty()) {
			throw new DequeEmptyException();
		}


		int ret = rear->data;


		Node* tmp = rear;
		if (rear->prev != NULL)
		{
			rear = rear->prev;
			rear->next = NULL;
		}
		else
		{
			rear = NULL;
		}
		count--;
		delete tmp;

		return ret;
	}

	int Front()
	{
		if (isEmpty())
			throw new DequeEmptyException();

		return front->data;
	}

	int Back()
	{
		if (isEmpty())
			throw new DequeEmptyException();

		return rear->data;
	}

	int Size()
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0 ? true : false;
	}
};

int main()
{

	Deque q;
	try {
		if (q.isEmpty())
		{
			cout << "Deque is empty" << endl;
		}


		q.InsertBack(100);
		q.InsertBack(200);
		q.InsertBack(300);


		cout << "Size of dequeue = " << q.Size() << endl;


		cout << q.RemoveBack() << endl;
		cout << q.RemoveBack() << endl;
		cout << q.RemoveBack() << endl;
	}
	catch (...) {
		cout << "Some exception occured" << endl;
	}


	Deque q1;
	try {
		if (q1.isEmpty())
		{
			cout << "Deque is empty" << endl;
		}


		q1.InsertBack(100);
		q1.InsertBack(200);
		q1.InsertBack(300);


		cout << "Size of dequeue = " << q1.Size() << endl;


		cout << q1.RemoveFront() << endl;
		cout << q1.RemoveFront() << endl;
		cout << q1.RemoveFront() << endl;
	}
	catch (...) {
		cout << "Some exception occured" << endl;
	}

	system("pause");
}
