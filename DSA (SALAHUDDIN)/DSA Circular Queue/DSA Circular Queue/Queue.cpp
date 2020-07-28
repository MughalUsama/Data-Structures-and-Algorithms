#include"Queue.h"

template<typename T>
Queue<T>::Queue(int cap)
{
	if (cap > 0)
	{
		front = 0;
		back = -1;
		capacity = cap;
		data = new T[cap];
	}
	else
	{
		front = 0;
		back = -1;
		capacity = 10;
		data = new T[capacity];
		throw "Invalid Capacity Passed!";
	}
}

template<typename T>
Queue<T>::Queue(Queue<T>& ref)
{
	front = ref.front;
	back = ref.back;
	capacity = ref.capacity;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = ref.data[i];
}

template<typename T>
void Queue<T>::enQueue(T val)
{
	if (!isFull())
	{
		data[(back+1)%capacity] = val;
		back++;
	}
	else
		throw "Queue is Full";
}

template<typename T>
T Queue<T>::deQueue()
{
	if (!isEmpty())
	{
		int temp = front % capacity;
		front++;
		return data[temp];
	}
	else
		throw "Queue is Empty";
}

template<typename T>
bool Queue<T>::isFull()
{
	return ((back+2) % (capacity+1) == front);
}

template<typename T>
bool Queue<T>::isEmpty()
{
	return front == back+1;
}

template<typename T>
Queue<T>::~Queue()
{
	if (data != nullptr)
		data = nullptr;
	capacity = 0;
	front = 0;
	back = -1;
}
