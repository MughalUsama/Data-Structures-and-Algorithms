#ifndef STACK_SLL_H
#define STACK_SLL_H

#include "SingleLinkedList.h"

template <class T>
class STACK_SLL
{

	private:
		SinglyLinkedList<T> *data;
		int noOfElements;
		
	public:
		STACK_SLL();
		~STACK_SLL();
		STACK_SLL(const STACK_SLL&);
		STACK_SLL & operator=(const STACK_SLL& ref);
		bool isEmpty()const;
		int getNoOfElements()const;
		T top();
		void push(T element);
		void pop();
};
	


template<class T>
inline STACK_SLL<T>::STACK_SLL()
{
	data = SinglyLinkedList <T>;
}

template<class T>
inline STACK_SLL<T>::~STACK_SLL()
{
	data->~SinglyLinkedList();
	this->noOfElements = 0;
}

template<class T>
inline STACK_SLL<T>::STACK_SLL(const STACK_SLL &)
{
}

template<class T>
STACK_SLL<T> & STACK_SLL<T>::operator=(const STACK_SLL & ref)
{
	// TODO: insert return statement here
}

template<class T>
inline bool STACK_SLL<T>::isEmpty() const
{
	return (data->getHead()==nullptr);
}


template<class T>
inline int STACK_SLL<T>::getNoOfElements() const
{
	int elements = 0;
	SinglyLinkedList <T> temp = data->getHead();
	while (temp.getHead()!=nullptr)
	{
		temp.head = temp.getNext();
		elements++;
	}
	return elements;
}

template<class T>
inline T STACK_SLL<T>::top()
{

	return T();
}

template<class T>
inline void STACK_SLL<T>::push(T element)
{
	data->getHead();

}

template<class T>
inline void STACK_SLL<T>::pop()
{
}

#endif