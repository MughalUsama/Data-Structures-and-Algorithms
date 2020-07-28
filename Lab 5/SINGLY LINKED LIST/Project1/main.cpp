#include <iostream>
#include "SingleLinkedList.h"
#include "C:\\Users\\Usama Shahid\\Desktop\\C++\\DSA\\Lab 4\\Stack\\Stack\\myStack.h"
#include "C:\\Users\\Usama Shahid\\Desktop\\C++\\DSA\\Lab 4\\Stack\\Stack\\myStack.cpp"

using namespace std;

template<class T>
T findKthLastElement(SinglyLinkedList<T> &list,int K)
{
	Node<T> * temp1 = list.getHead();
	Node<T> * temp2 = list.getHead();
	int count = 1;
	if (K > 0)
	{
		while (count != K && temp2->next != nullptr)
		{
			temp2 = temp2->next;
			count++;			
		}
		if (count == K)
		{
			while (temp2->next != nullptr)
			{
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			return temp1->value;
		}
	}
	throw "Out of Range";
}
template<class T>
T findMiddleElement(SinglyLinkedList<T> &list)
{
	Node<T> * temp1 = list.getHead();
	Node<T> * temp2 = list.getHead();
	
	while (temp2->next != nullptr)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
		if (temp2->next!=nullptr)
		{
			temp2 = temp2->next;
		}
	}

	return temp1->value;
	
}

template<class T>
bool isPalindrome(SinglyLinkedList<T> &list)
{
	Stack<T> s;
	Node<T> * temp1 = list.getHead();
	while (temp1!=nullptr)
	{
		s.push(temp1->value);
		temp1 = temp1->next;
	}
	Node<T> * temp2 = list.getHead();
	while (temp2 != nullptr)
	{
		if (temp2->value != s.top())
		{
			return false;
		}
		s.pop();
		temp2 = temp2->next;
	}
	return true;
}

template<class T>
void partitioning(SinglyLinkedList<T> &list, int x)
{
	Node<T> * temp1 = list.getHead();
	Node<T> * tail = new Node<T>(temp1->value, nullptr);
	Node<T> * head1 = tail;
	list.deleteNode(1);
	while (temp1->next!=nullptr)
	{
		if (temp1->value >= x)
		{
			tail->next = new Node<T>(temp1->value,nullptr);
			tail = tail->next;

		}
		else
		{
			Node<T> * temp2 = new Node<T>(temp1->value, head1);
			head1 = temp2;

		}
		list.deleteNode(1);
//		temp1 = temp1->next;
	
	
	}
	list.setHead(head1);
}


int main()
{
	SinglyLinkedList<int> list;
	list.addElement(2);
	list.addElement(4);
	//list.addElement(5);
	list.addElement(7);
	list.addElement(9);
	list.addElement(5);
//	list.deleteNode(1);
	partitioning(list, 7);
	list.display();
	/*list.insertBefore(5, 3);
	list.display();*/

//	cout << findKthLastElement(list,25);

	return 0;
}