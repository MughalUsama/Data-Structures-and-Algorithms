#ifndef SingleLL_H
#define SingleLL_H
#include <iostream>
using namespace std;


template<class T>
struct Node
{
	T value;
	Node * next;
	Node(T val, Node * nextPtr= nullptr)
	{
		this->value = val;
		this->next = nextPtr;
	}
};

template<class T>
class SinglyLinkedList
{

	private:
		Node<T> * head;

	public:
		SinglyLinkedList();
		SinglyLinkedList(const SinglyLinkedList<T>& obj);
		~SinglyLinkedList();
		void addElement(T val);

		
		Node<T>* getHead ();
		void setHead(Node<T>* n);
		Node<T>* getNext(Node<T>* n);
		T getValue(Node<T>* n);
		bool insertBefore(T find, T insert);
		void deleteNode(int nodeNo);
		void display();

};

template<class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	this->head = nullptr;
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	if (head != 0)
	{
		Node<T> * nextN = head;
		Node<T> * prevoiusN = head;
		while (nextN != nullptr)
		{
			nextN = nextN->next;
			delete prevoiusN;
			prevoiusN = nextN;
		}
		
		delete prevoiusN;
		head = nullptr;
	}
}
template<class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& obj)
{
	if (obj.head != nullptr)
	{
		Node<T> * temp = obj.head;
		while (temp != nullptr)
		{
			this->addElement(temp->value);
			temp = temp->next;
		}
	}
}
template<class T>
void SinglyLinkedList<T>::addElement(T val)
{
	if (head == nullptr)
	{
		head = new Node<T>(val, nullptr);
	}
	else
	{
		Node<T> * temp = head;
		Node<T> * secondLast = temp;
		while (temp != nullptr)
		{
			secondLast = temp;
			temp = temp->next;
		}
		temp = new Node<T>(val, nullptr);
		secondLast->next = temp;
	}
}

template<class T>
Node<T> *SinglyLinkedList<T>::getHead()
{
	return head;
}
template<class T>
void SinglyLinkedList<T>::setHead(Node<T>* n)
{
	this->head = n;
}
template<class T>
 Node<T> * SinglyLinkedList<T>::getNext(Node<T>* n)
{
	 return n->next;
}
template<class T>
T SinglyLinkedList<T>::getValue(Node<T>* n)
{
	return n->value;
}
template<class T>
bool SinglyLinkedList<T>::insertBefore(T find, T insert)
{
	Node<T> *temp=head;
	while (temp->next != nullptr && temp->next->value!=find )
	{
		temp = temp->next;
	}

	if (temp->next != nullptr)
	{
		Node<T> * newNode = new Node<T>(insert,nullptr);
		newNode->next = temp->next;
		temp->next = newNode;
		return true;
	}
	return false;
}
template<class T>
void SinglyLinkedList<T>::deleteNode(int nodeNum)
{
	Node<T> * prevoius = head;
	Node<T> * nextN = head;
	for (int i = 0; i < nodeNum - 1; i++)
	{
		prevoius = nextN;
		nextN = nextN->next;
	}

	if (nodeNum-1!=0 && nextN->next != nullptr)
	{
		prevoius = prevoius->next->next;
		delete nextN;
		nextN = nullptr;
	}
	else if (nodeNum - 1 != 0 && nextN->next == nullptr)
	{
		prevoius->next = nullptr;
		delete nextN;
		nextN = nullptr;
	}

	else if (nodeNum - 1 == 0 && nextN->next == nullptr)
	{
		delete nextN;
		head = nextN = prevoius = nullptr;
	}
	else 
	{
		nextN = nextN->next;
		delete prevoius;
		head = nextN;
	}
}
template<class T>
void SinglyLinkedList<T>::display()
{
	if (head)
	{
		cout << "List Elements :\n";
		Node<T> * temp = head;
		int i = 1;
		while (temp != nullptr)
		{
			cout <<  temp->value << '\n';
			temp = temp->next;
			i++;
		}
	}
}
#endif