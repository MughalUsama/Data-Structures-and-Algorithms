#include "SLinkedLists.h"


template<class T>
SLinkedLists<T>::SLinkedLists()
{
	this->head = nullptr;
}


template<class T>
SLinkedLists<T>::~SLinkedLists()
{
	Node * temp=head->next;
	while (head!=nullptr)
	{
		delete head;
		head = temp->next;
	}
}

