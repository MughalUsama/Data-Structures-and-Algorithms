#ifndef QUEUE_H
#define QUEUE_H
template<typename T>
class Queue
{
	int front;
	int back;
	int capacity;
	T *data;
public:
	Queue(int);
	Queue(Queue<T> &);
	void enQueue(T);
	T deQueue();
	bool isFull();
	bool isEmpty();
	~Queue();
};
#endif // !QUEUE_H
