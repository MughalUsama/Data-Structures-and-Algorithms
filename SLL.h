#ifndef SLL_H
#define SLL_H
#include"SLLNode.h"
template<class T>
class SLL
{
public:
	SLL();
	SLL(const SLL<T>& obj);
	~SLL();
	void addElement(T val);
	int getLength();
	void deleteNode(int nodeNum);
	bool isInList(int value) const;
	void display();

private:
	Node<T> * head;
};
template<class T>
SLL<T>::SLL()
{
	this->head = nullptr;
}
template<class T>
SLL<T>::~SLL()
{
	if (head != 0)
	{
		Node<T> * nextN = head;
		Node<T> * prevoiusN = head;
		while (nextN != nullptr)
		{
			nextN = nextN->ptrToNextNode;
			delete prevoiusN;
			prevoiusN = nextN;
		}
		// The above while loop will delete all values before the last value 
		delete prevoiusN;
		head = nullptr;
	}
}
template<class T>
SLL<T>::SLL(const SLL<T>& obj)
{
	if (obj.head != nullptr)
	{
		Node<T> * temp = obj.head;
		while (temp != nullptr)
		{
			this->addElement(temp->value);
			temp = temp->ptrToNextNode;
		}
	}
}
template<class T>
void SLL<T>::addElement(T val)
{
	if (head == nullptr)
		head = new Node<T>(val, nullptr);
	else
	{
		Node<T> * temp = head;
		Node<T> * secondLast = temp;
		while (temp != nullptr)
		{
			secondLast = temp;
			temp = temp->ptrToNextNode;
		}
		temp = new Node<T>(val , nullptr);
		secondLast->ptrToNextNode = temp;
	}
}
template<class T>
int SLL<T>::getLength()
{
	int len = 0;
	Node<T> * temp = head;
	while (temp != nullptr)
	{
		temp = temp->ptrToNextNode;
		len = len + 1;
	}
	return len;
}
template<class T>
void SLL<T>::deleteNode(int nodeNum)
{
	Node<T> * prevoius = head;
	Node<T> * nextN = head;
	for (int i = 0; i < nodeNum - 1; i++)
	{
		prevoius = nextN;
		nextN = nextN->ptrToNextNode;
	}
	// now I am at element that is before the nodeNum element
	// if the elemant that has to delete is not last element and not the first element
	if (nextN->next != nullptr)
	{
		prevoius = prevoius->ptrToNextNode->ptrToNextNode;
		delete nextN;
		nextN = nullptr;
	}
	// if the elemant that has to delete is last element
	else if (nextN->next == nullptr)
	{
		prevoius->ptrToNextNode = nullptr;
		delete nextN;
		nextN = nullptr;
	}
	// if the elemant that has to delete is first element or last element and only one element in LL
	else if (nodeNum - 1 == 0 && nextN->ptrToNextNode == nullptr)
	{
		delete nextN;
		head = nextN = prevoius = nullptr;
	}
	// if the elemant that has to delete is first element or last element and many elements in LL
	else //if(nodeNum == 0 && nextN->ptrToNextNode != nullptr)
	{
		nexN = nextN->ptrToNextNode;
		delete prevoius;
		head = nextN;
	}
}
template<class T>
void SLL<T>::display()
{
	if (head)
	{
		cout << "Elements :\n";
		Node<T> * temp = head;
		int i = 1;
		while (temp != nullptr)
		{
			cout << i << " : " << temp->value << '\n';
			temp = temp->ptrToNextNode;
			i++;
		}
	}
}
#endif // !S_LINK_LIST_H