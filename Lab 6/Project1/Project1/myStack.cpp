#include "myStack.h"
#include <iostream>
using namespace std;



template <class T>
Stack <T>::Stack()
{
	this->data = new T[10];
	this->capacity = 10;
	this->noOfElements = 0;
}

template <class T>
Stack<T>::~Stack()
{
	if (this->data!=nullptr)
	{
		delete[] this->data;
	}
	this->capacity = 0;
	this->noOfElements = 0;
}

template<class T>
Stack<T>::Stack(const Stack & ref)
{
	this->capacity = ref.capacity;
	this->noOfElements = ref.noOfElements;
	this->data = new T[capacity];
	for (int i = 0; i < noOfElements; i++)
	{
		this->data[i] = ref.data[i];
	}
}

template<class T>
Stack<T> & Stack<T>::operator=(const Stack & ref)
{
	if (&ref==this)
	{
		return *this;
	}
	this->~Stack();
	this->capacity = ref.capacity;
	this->noOfElements = ref.noOfElements;
	this->data = new T[capacity];
	for (int i = 0; i < noOfElements; i++)
	{
		this->data[i] = ref.data[i];
	}
	return *this;
}

template<class T>
bool Stack<T>::isFull()const
{
	if (this->capacity==this->noOfElements)
	{
		return true;
	}
	return false;
}

template<class T>
bool Stack<T>::isEmpty()const
{
	if (this->noOfElements==0)
	{
		return true;
	}
	return false;
}

template<class T>
int Stack<T>::getCapacity()const
{
	return this->capacity;
}

template<class T>
int Stack<T>::getNoOfElements()const
{
	return noOfElements;
}

template<class T>
void Stack<T>::resize()
{
	T * temp = new T[this->capacity*1.5];
	for (int i = 0; i < this->noOfElements; i++)
	{
		temp[i] = this->data[i];
	}
	this->capacity = this->capacity*1.5;
	delete[] this->data;
	this->data = temp;
}

template<class T>
T Stack<T>::top()
{
	if (this->noOfElements>0)
	{
		return this->data[noOfElements-1];
	}
	throw "Stack is Empty";
}

template<class T>
void Stack<T>::push(T element)
{
	if (isFull())
	{
		this->resize();
	}
	this->data[noOfElements] = element;
	noOfElements++;
}

template<class T>
void Stack<T>::pop()
{
	if (!isEmpty())
	{
		this->noOfElements--;
	}	
	else
	{
		throw "Stack is Empty";
	}

}

template<class T>
void Stack<T>::display()
{
	int i = 0;
	while (i<this->noOfElements)
	{
		cout << this->data[i];
		i++;
	}
}

template<class T>
bool isSyntaxValid(const char *str)
{
	Stack<char> charStack;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!charStack.isEmpty())
		{
			if (str[i] == ')' && charStack.top() == '(')
			{
				charStack.pop();
			}
			else if (str[i] == '}' && charStack.top() == '{')
			{
				charStack.pop();
			}
			else if (str[i] == ']' && charStack.top() == '[')
			{
				charStack.pop();
			}
			else if (str[i] == ']' || str[i] == '}' || str[i] == ')')
			{
				return false;//if no opening brace for closing brace found on stack  e.g((}
			}
			else if (str[i] == '[' || str[i] == '{' || str[i] == '(')
			{
				charStack.push(str[i]);//making sure only braces are pushed to stack
			}
		}
		else if (str[i] == '[' || str[i] == '{' || str[i] == '(')
		{

			charStack.push(str[i]);//making sure only braces are pushed to stack
		}
		else if (str[i] == ']' || str[i] == '}' || str[i] == ')')
		{
			return false;
		}
	}
	if (charStack.isEmpty())
	{
		return true;
	}
	return false;
}