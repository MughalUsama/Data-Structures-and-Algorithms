#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class Queue
{
private:
	T *data;
	int capacity;
	int front;		//index
	int back;		//index
public:
	Queue();
	~Queue();
	void enqueue(T&);
	T dequeue();
	bool isFull();
	bool isEmpty();
};

#endif