#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
using namespace std;


template<typename T>
class MinHeap
{
	T* heapArray; 
	int capacity; 
	int noOfElements;

	void swapValues(T& x, T& y);
	void printPreorder(int index);
public:

	MinHeap();
	MinHeap(int capacity);
	~MinHeap();
	void insert(int key);    
	T extractMin();
	void deleteKey(int i);
	void display();
	void heapifyUp(int i);
	void minHeapify(int i);
	void display1()
	{
		for (int i = 0; i < 10; i++)
		{
			cout << heapArray[i]<<" ";
		}
	}
	int parent(int i) 
	{ 
		if (i > 0 && i<noOfElements)
		{
		return (i - 1) / 2;
		}
		throw  "Out of range. No parent exists";
	}
	int left(int i)
	{
		int index = 2 * i + 1;
		if (index >= 0 && index <noOfElements)
		{
			return (2 * i + 1);
		}
		else
		{
			throw "out of range1";
		}
	}

	int right(int i)
	{
		int index = 2 * i + 2;
		if (index >= 0 && index < noOfElements)
		{
			return (2 * i + 2);
		}
		else
		{
			throw "out of range";
		}	
	}

	T getMin()          	 
	{
		return heapArray[0]; 
	}

};

template<typename T>
MinHeap<T>::MinHeap()
{
	noOfElements = 0;
	capacity = 10;
	heapArray = new int[capacity];
}

template<typename T>
MinHeap<T>::MinHeap(int cap)
{
	noOfElements = 0;
	capacity = cap;
	heapArray = new int[cap];
}

template<typename T>
MinHeap<T>::~MinHeap()
{
	delete[] this->heapArray;
	this->noOfElements = 0;
	this->capacity = 0;
}


template<typename T>
void MinHeap<T>::insert(int k)
{
	if (noOfElements == capacity)
	{
		cout << "\nSize Of Heap exceeded!\n";
		return;
	}

	noOfElements++;
	int i = noOfElements - 1;
	heapArray[i] = k;
	heapifyUp(i);
}


//

template<typename T>
T MinHeap<T>::extractMin()
{
	if (noOfElements <= 0)
		throw "Heap is empty";
	if (noOfElements == 1)
	{
		noOfElements--;
		return heapArray[0];
	}
	T root = heapArray[0];
	heapArray[0] = heapArray[noOfElements - 1];
	noOfElements--;
	minHeapify(0);

	return root;
}



template<typename T>
void MinHeap<T>::deleteKey(int i)
{
	heapArray[i] = INT_MIN;
	heapifyUp(i);
	extractMin();
}

template<typename T>
void MinHeap<T>::display()
{
	printPreorder(0);
}

template<typename T>
void MinHeap<T>::heapifyUp(int i)
{
	while (i != 0 && heapArray[parent(i)] > heapArray[i])
	{
		swapValues(heapArray[i], heapArray[parent(i)]);
		i = parent(i);
	}
}


template<typename T>
void MinHeap<T>::minHeapify(int i)
{
	try
	{
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < noOfElements && heapArray[l] < heapArray[i])
		{
			smallest = l;
		}
		if (r < noOfElements && heapArray[r] < heapArray[smallest])
		{
			smallest = r;
		}
		if (smallest != i)
		{
			swapValues(heapArray[i], heapArray[smallest]);
			minHeapify(smallest);
		}
	}
	catch (const char *)
	{
		return;
	}	
}

template<typename T>
void MinHeap<T>::printPreorder(int index)
{
	if (index >= noOfElements)
		return;

	cout << heapArray[index] << " ";


	printPreorder(2* index +1);

	printPreorder(2 * index + 2);
}

template<typename T>
void MinHeap<T>::swapValues(T & x, T & y)
{
	T temp = x;
	x = y;
	y = temp;
}


#endif // !1