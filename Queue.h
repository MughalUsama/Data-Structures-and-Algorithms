#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class Queue
{
private:
	T * data;
	int front; // it is an index of element that is previously entered
	int back;  // it is the index of element that is recently entered
	int capacity;
	void resize();
public:
	Queue(int cap = 10);				// parameterized constructor
	Queue(const Queue<T> & ref);	// copy constructor
	~Queue();						//destructor 
	void enqueue(T element);
	T deqeue();
	int getCapacity() const;
	int getNumOfElements();
	T firstEl();
	Queue<T> operator=(const Queue<T> & ref);
	T operator()(int index);
	void clear();
	void display();
	bool isFull();
	bool isEmpty() const;

};
template<class T>
bool Queue<T>::isFull()
{
	//return front == 0 && (front == back + 1 || back == capacity - 1);
	return (back + 1) % capacity == front;
}
template<class T>
bool Queue<T>::isEmpty() const
{
	return front == -1;
}
template<class T>
Queue<T>::Queue(int cap)
{
	this->capacity = cap;
	data = new T[cap];
	this->front = this->back = -1;
}
template<class T>
Queue<T>::~Queue()
{
	if (data)
	{
		delete[] this->data;
	}
	this->front = this->back = -1,
	this->capacity = 0;
}
template<class T>
Queue<T>::Queue(const Queue<T> & ref)
{ 
	this->capacity = ref.capacity;
	this->back = ref.back;
	this->front = ref.front;
	this->data = new T[this->capacity];
	if (this->data)
	{
		if (back < front)
		{
			for (int i = front; i < capacity; i++)
			{
				data[i] = ref.data[i];
			}
			for (int i = 0; i <= back; i++)
			{
				data[i] = ref.data[i];
			}

		}
		else
		{
			for (int i = front; i <= back; i++)
			{
				data[i] = ref.data[i];
			}
		}
	}
}
template<class T>
void Queue<T>::enqueue(T element)
{
	if (!isFull())
	{
		if (back == capacity - 1 || back == -1)
		{
			data[0] = element;
			back = 0;
			if (front == -1)
				front = 0;
		}
		else
			data[++back] = element;
	}
	else
		cout << "Queue is full";
}
template<class T>
T Queue<T>::deqeue()
{
	if (!isEmpty())
	{
		int temp = data[front];
		if (front == back)
			front = back = -1;
		else if (front == capacity - 1)
			front = 0;
		else
			front++;
		return temp;
	}
	else
		throw "Queue is Empty";
}
template<class T>
int Queue<T>::getCapacity() const
{
	return this->capacity;
}
template<class T>
int Queue<T>::getNumOfElements()
{
	if(back < front) // if queue is circulate
		return (capacity - front) + back + 1;
	else
	{
		if(!this->isEmpty())
			return (back - front + 1);
		return 0; // for empty queue
	}
}
template<class T>
void Queue<T>::clear() 
{
	if (front != -1 && back != -1)
		front = back = -1;
}
template<class T>
Queue<T> Queue<T>::operator=(const Queue<T> & ref)
{
	if (&ref != this)
	{
		this->capacity = ref.capacity;
		this->back = ref.back;
		this->front = ref.front;
		this->data = new T[this->capacity];
		if (this->data)
		{
			if (back < front)
			{
				for (int i = front; i < capacity; i++)
				{
					data[i] = ref.data[i];
				}
				for (int i = 0; i <= back; i++)
				{
					data[i] = ref.data[i];
				}

			}
			else
			{
				for (int i = front; i <= back; i++)
				{
					data[i] = ref.data[i];
				}
			}
		}
	}
	return *this;
}
template<class T>
T  Queue<T>::firstEl()
{
	if (front == -1)
		return data[front];
	else
		throw "Queue is Empty";
}
template<class T>
void Queue<T>::display()
{
	if (!isEmpty())
	{
		cout << "Elements \n";
		if (back < front)
		{
			/*int nOE = (capacity - front) + back + 1;
			for (int i = front; i < nOE; i++)
			{
				cout << i + 1 << " : " << this->data[i] << '\n';
			}*/
			for (int i = front; i < capacity; i++)
			{
				cout << i + 1 << " : " << this->data[i] << '\n';
			}
			for (int i = 0; i <= back ; i++)
			{
				cout << i + 1 << " : " << this->data[i] << '\n';
			}

		}
		else
		{
			for (int i = front; i <= back; i++)
			{
				cout << i + 1 << " : " << this->data[i] << '\n';
			}
		}
	}
	else
		cout << "Queue is empty";
}
template<class T>
T Queue<T>::operator()(int index)
{
	if (index >= front && index <= this->back)
		return this->data[index];
	throw out_of_range("Index is out of range");
}
template<class T>
void Queue<T>::resize()
{
	int newCap = capacity + 1;
	T * tempData = new T[newCap];
	int i;
	for (i = 0; i <= back; i++)
	{
		tempData[i] = data[i];
	}
	if (front = back + 1)
	{
		int tmp = i;
		for (i = front + 1; i < newcap; i++)
		{
			tempData[i] = data[i - 1];
		}
		front = tmp + 1;
	}
	delete[] this->data;
	this->data = tempData;
	this->capacity = newCap;
	tempData = 0;
}
#endif // !QUEUE_H