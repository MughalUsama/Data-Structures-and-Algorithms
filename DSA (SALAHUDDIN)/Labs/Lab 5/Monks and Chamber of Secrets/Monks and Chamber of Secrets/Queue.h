#ifndef QUEUE_H
#define QUEUE_H
template<class T>
class Queue {
private:
	T * data;
	int back;
	int front;
	int capacity;
public:
	Queue();
	Queue(int capacity);
	Queue(const Queue & ref);
	Queue & operator = (const Queue & ref);
	~Queue();
	int getCapacity()const;
	bool isFull()const;
	bool isEmpty()const;
	void clearQueue();
	T firstEle()const;
	void enQueue(T element);
	T deQueue();
	void displayQueue()const;
};
#endif
template<class T>
Queue<T>::Queue() 
{
	this->capacity = 10;
	this->data = new int[this->capacity];
	this->back = -1;
	this->front = -1;
}
template<class T>
Queue<T>::Queue(int capacity) 
{
	if(capacity>0)
		this->capacity=capacity;
	else
		this->capacity = 10;
	this->data = new int[this->capacity];
	this->back = -1;
	this->front = -1;
}
template<class T>
Queue<T>::Queue(const Queue & ref)
{
	this->capacity = ref.capacity;
	this->data = new T[this->capacity];
	for (int i = 0; i < this->capacity; i = i + 1)
		this->data[i] = ref.data[i];
	this->back = ref.back;
	this->front = ref.front;
}
template<class T>
Queue<T> & Queue<T>::operator = (const Queue & ref)
{
	if (this != (&ref))
	{
		this->capacity = ref.capacity;
		delete[] this->data;
		this->data = new T[this->capacity];
		for (int i = 0; i < this->capacity; i = i + 1)
			this->data[i] = ref.data[i];
		this->back = ref.back;
		this->front = ref.front;
	}
	return (*this);
}
template<class T>
Queue<T>::~Queue()
{
	if (this->data != NULL)
	{
		delete[] this->data;
		this->data = NULL;
	}
}
template<class T>
int Queue<T>::getCapacity()const
{
	return this->capacity;
}
template<class T>
bool Queue<T>::isFull()const 
{
	return ((this->back + 1) % this->capacity == this->front);
}
template<class T>
bool Queue<T>::isEmpty()const 
{
	if (this->back == -1 && this->front == -1)
		return true;
	else
		return false;
}
template<class T>
T Queue<T>::firstEle()const
{
	if(!this->isEmpty())
		return this->data[this->front];
}
template<class T>
void Queue<T>::clearQueue()
{
	this->back = -1;
	this->front = -1;
}
template<class T>
void Queue<T>::enQueue(T element)
{
	if (!this->isFull()) {
		if (this->isEmpty())
		{
			this->data[0] = element;
			this->front = 0;
			this->back = 0;
		}
		else if (this->back == this->capacity - 1)
		{
			this->data[0] = element;
			this->back = 0;
		}
		else
		{
			this->data[++this->back] = element;
		}
	}
}
template<class T>
T Queue<T>::deQueue()
{
	if (this->front == this->back)
	{
		int temp = this->front;
		this->back = -1;
		this->front = -1;
		return this->data[temp];
	}
	else if (!this->isEmpty())
	{
		if (this->front == this->capacity - 1)
		{
			this->front = 0;
			return this->data[this->capacity - 1];
		}
		else
		{
			this->front++;
			return this->data[this->front - 1];
		}
	}
}
template<class T>
void Queue<T>::displayQueue()const
{
	int i = this->front;
	while (i != this->back)
	{
		cout << this->data[i] << " ";
		if (i == this->capacity - 1)
			i = 0;
		else
			i = i + 1;
	}
	cout << this->data[i] << " \n";
}
