#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
private:
	T *data;
	int noOfElements;
	int capacity;
	void resize();
public:
	Stack();
	~Stack();
	Stack(const Stack&);
	Stack & operator=(const Stack & ref);
	bool isFull()const;
	bool isEmpty()const;
	int getCapacity()const;
	int getNoOfElements()const;
	T top();
	void push(T element);
	void pop();
	void display();
};

#endif