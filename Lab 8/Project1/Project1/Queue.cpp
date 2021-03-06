#include "Queue.h"


template<class T>
Queue<T>::Queue(int size)
{
	data = new T[size];
	capacity = size;
	front = -1;
	back = -1;
}

template<class T>
Queue<T>::~Queue()
{
	delete[] data;
	capacity = 0;
	front = -1;
	back = -1;
}

template<class T>
void Queue<T>::enqueue(T & value)
{
	if (!isFull())
	{		if (back == capacity - 1 || back == -1) {
				data[0] = value;
				back = 0;
				if (front== -1)
					front = 0;
			}
			else data[++back] = value;
	}
}

template<class T>
T Queue<T>::dequeue()
{
	T tmp;
	tmp = data[front];
	if (front == back)
		back = front = -1;
	else if (front== capacity- 1)
		front = 0;
	else front++;
	return tmp;
}


template<class T>
bool Queue<T>::isFull()
{
	return (back+1%capacity==front);
}  

template<class T>
bool Queue<T>::isEmpty()
{
	return (this->back == -1 && this->front == -1);
}

template<class T>
T Queue<T>::getFront()
{
	if (!isEmpty())
	{
		return this->data[front];
	}
	throw " Empty queue";

}



