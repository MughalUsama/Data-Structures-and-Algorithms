#include "SLinkList.h"
#include<iostream>
using namespace std;
template<typename T>
SLinkList<T>::SLinkList()
{
	head = nullptr;
}

template<typename T>
SLinkList<T>::SLinkList(const SLinkList<T> & ref)
{
	if (ref.head != nullptr)
	{
		head = new Node<T>((ref.head)->value, (ref.head)->ptrToNext);
		Node<T> *ptr = head, *ptr2= (ref.head)->ptrToNext;
		while (ptr2 != nullptr)
		{
			ptr->ptrToNext = new Node<T>(ptr2->value, ptr2->ptrToNext);
			ptr = ptr->ptrToNext;
			ptr2 = ptr2->ptrToNext;
		}
	}
	else
		head = nullptr;
}

template<typename T>
void SLinkList<T>::addElement(T val)
{
	if (head == nullptr)
		head = new Node<T>(val, nullptr);
	else
	{ 
		Node<T> *ptr = head;
		while (ptr->ptrToNext != nullptr)
			ptr = ptr->ptrToNext;
		ptr->ptrToNext = new Node<T>(val, nullptr);
	}
}

template<typename T>
void SLinkList<T>::removeElement(int index)
{
	if (index == 0)
	{
		Node<T> *ptr = head->ptrToNext;
		delete head;
		head = ptr;
	}
	else if (index < getLength())
	{
		Node<T> *ptr = head;
		while (index > 1)
		{
			ptr = ptr->ptrToNext;
			index--;
		}
		Node<T> *ptr2 = (ptr->ptrToNext)->ptrToNext;
		delete ptr->ptrToNext;
		ptr->ptrToNext = ptr2;
	}
	else
		throw "Invalid Index!";
}

template<typename T>
int SLinkList<T>::getLength()
{
	Node<T> *ptr = head;
	int length = 0;
	while (ptr != nullptr)
	{
		ptr = ptr->ptrToNext;
		length++;
	}
	return length;
}

template<typename T>
void SLinkList<T>::display()
{
	Node<T> *ptr = head;
	while (ptr != nullptr)
	{
		cout << ptr->value<<' ';
		ptr = ptr->ptrToNext;
	}
}

template<typename T>
SLinkList<T>& SLinkList<T>::reverse()
{
	if (head != nullptr)
	{
		int length = this->getLength();
		for (int i = length-1; i > 0; i--)
		{
			Node<T> *ptr = head, *ptr2 = head->ptrToNext;
			for (int j = i; j > 0; j--)
			{
				T temp = ptr->value;
				ptr->value = ptr2->value;
				ptr2->value = temp;
				ptr = ptr->ptrToNext;
				ptr2 = ptr2->ptrToNext;
			}
		}
	}
	else
		throw "List is Empty!";
	return *this;
}

template<typename T>
SLinkList<T>& SLinkList<T>::sort()
{
	if (head != nullptr)
	{
		int length = this->getLength();
		bool swap=true;
		while (swap)
		{
			swap = false;
			Node<T> *ptr = head, *ptr2 = head->ptrToNext;
			for (int j = length-1; j > 0; j--)
			{
				if (ptr->value > ptr2->value)
				{
					T temp = ptr->value;
					ptr->value = ptr2->value;
					ptr2->value = temp;
					swap = true;
				}
				ptr = ptr->ptrToNext;
				ptr2 = ptr2->ptrToNext;
			}
		}
	}
	else
		throw "List is Empty!";
	return *this;
}

template<typename T>
SLinkList<T>::~SLinkList()
{
	if (head != nullptr)
	{
		Node<T> *ptr1 = head, *ptr2 = head;
		while(ptr1 != nullptr)
		{ 
			ptr1 = ptr1->ptrToNext;
			delete ptr2;
			ptr2 = ptr1;
		}
		head = nullptr;
	}
}
