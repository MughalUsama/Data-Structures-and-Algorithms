#ifndef S_LINK_LIST_H
#define S_LINK_LIST_H
#include<iostream>
using namespace std;
template<class T>
struct Node
{
public:
	T data;
	Node * next;
	Node(T value)
	{
		this->data = value;
		this->next = nullptr;
	}
};
template<class R>
class S_Link_List
{
private:
	Node<R> * head;
	int calcLengthR(Node<R> * ptr)const;
	R findMinimumR(Node<R> * ptr , R min)const;
	Node<R> * reverseListR(Node<R> * ref);
public:
	S_Link_List<R>();
	S_Link_List(R val);
	S_Link_List(const S_Link_List & ref);
	~S_Link_List<R>();
	Node<R> * getHead()const;
	int getLength()const;
	void addNewNode(R data);
	void removeNode();
	bool searchEle(R element)const;
	void deleteEle(R element);
	void sortList();
	void reverseList();
	bool isEmpty()const;
	void display_List()const;
	bool insertBefore(R find, R insert);

	int getLengthR(const S_Link_List & ref)const;
	R getMinimumR(const S_Link_List & ref)const;
	Node<R> * reverseListRR();

	template<class F>
	friend F findKthLastElement(const S_Link_List<R> & ref, int k);
	template<class F>
	friend void sortLinkList(S_Link_List<R> & ref);
	template<class F>
	friend bool isListPalindrome(const S_Link_List<R> & ref);
	template<class F>
	friend void partitioning(S_Link_List<F> & ref, int value);
	template<class F>
	friend void findAndBreakLoop(S_Link_List<F> & ref);

};
#endif
template<class R>
S_Link_List<R>::S_Link_List()
{
	this->head = nullptr;
}
template<class R>
S_Link_List<R>::S_Link_List(R val)
{
	this->head = new Node<R>(val , nullptr);
}
template<class R>
S_Link_List<R>::S_Link_List(const S_Link_List & ref)
{
	if (ref.head != nullptr)
	{
		Node<R> * refTemp = ref.head;
		this->head = new Node<R>(refTemp->data, nullptr);
		Node<R> * callingTemp = this->head;
		while (refTemp->next != nullptr)
		{
			callingTemp->data = refTemp->data;
			callingTemp->next = new Node<R>(refTemp->data, nullptr);
			callingTemp = callingTemp->next;
			refTemp = refTemp->next;
		}
		callingTemp->data = refTemp->data;
	}
}
template<class R>
S_Link_List<R>::~S_Link_List()
{
	if (this->head != nullptr)
	{
		Node<R> * callingTemp1 = this->head;
		Node<R> * callingTemp2 = this->head;
		while (callingTemp1->next != nullptr)
		{
			callingTemp2 = callingTemp2->next;
			delete callingTemp1;
			callingTemp1 = callingTemp2;
		}
		delete callingTemp1;
		callingTemp1 = nullptr;
		this->head = nullptr;
	}
}
template<class R>
Node<R> * S_Link_List<R>::getHead()const
{
	return this->head;
}
template<class R>
int S_Link_List<R>::getLength()const
{
	int length = 0;
	if (this->head != nullptr)
	{
		Node<R> * temp = this->head;
		while (temp->next != nullptr)
		{
			length = length + 1;
			temp = temp->next;
		}
		return length + 1;
	}
	return length;
}
template<class R>
void S_Link_List<R>::addNewNode(R data)
{
	if (this->isEmpty())
	{
		this->head = new Node<R>(data);
	}
	else
	{
		Node<R> * callingTemp = this->head;
		while (callingTemp->next != nullptr)
		{
			callingTemp = callingTemp->next;
		}
		callingTemp->next = new Node<R>(data);
	}	
}
template<class R>
void S_Link_List<R>::removeNode()
{
	if (!this->isEmpty())
	{
		if (this->head->next == nullptr)
		{
			delete this->head;
			this->head = nullptr;
		}
		else
		{
			Node<R> * callingTemp = this->head;
			while (callingTemp->next->next != nullptr)
			{
				callingTemp = callingTemp->next;
			}
			delete callingTemp->next;
			callingTemp->next = nullptr;
		}
	}
}
template<class R>
bool S_Link_List<R>::searchEle(R element)const
{
	if (!this->isEmpty())
	{
		Node<R> * callingTemp = this->head;
		while (callingTemp->next != nullptr)
		{
			if (callingTemp->data == element)
				return true;
			callingTemp = callingTemp->next;
		}
		return callingTemp->data == element;
	}
	return false;
}
template<class R>
void S_Link_List<R>::deleteEle(R element)
{
	if (this->searchEle(element) == true)
	{
		if (this->head->next == nullptr)
		{
			delete this->head;
			this->head = nullptr;
		}
		else
		{
			Node<R> * callingTemp = this->head;
			bool isFound = false;
			while (callingTemp->next->next != nullptr)
			{
				if (isFound == false)
				{
					if (callingTemp->data == element)
					{
						callingTemp->data = callingTemp->next->data;
						isFound = true;
						callingTemp = callingTemp->next;
					}
					else
						callingTemp = callingTemp->next;
				}
				else
				{
					callingTemp->data = callingTemp->next->data;
					callingTemp = callingTemp->next;
				}
			}
			if((callingTemp->data==element && isFound==false)||(isFound==true))
				callingTemp->data = callingTemp->next->data;
			delete callingTemp->next;
			callingTemp->next = nullptr;
		}
	}
}
template<class R>
void S_Link_List<R>::sortList()
{
	if (this->head != nullptr && this->head->next != nullptr)
	{
		bool isSorted = true;
		Node<R> * temp = this->head;
		R tempEle;
		while (temp->next != nullptr)
		{
			if (temp->data > temp->next->data)
			{
				tempEle = temp->data;
				temp->data = temp->next->data;
				temp->next->data = tempEle;
				isSorted = false;
			}
			temp = temp->next;
			if (temp->next == nullptr && isSorted == false)
			{
				temp = this->head;
				isSorted = true;
			}
		}
	}
}
template<class R>
void S_Link_List<R>::reverseList()
{
	if (this->head != nullptr && this->head->next != nullptr)
	{
		int length = this->getLength();
		Node<R> ** indexes = new Node<R>*[length];
		Node<R> * temp = this->head;
		int i = 1;
		indexes[0] = nullptr;
		while (temp->next != nullptr)
		{
			indexes[i] = temp;
			temp = temp->next;
			i = i + 1;
		}
		temp = this->head;
		Node<R> * temp2 = this->head;
		i = 0;
		while (temp->next != nullptr)
		{
			temp2 = temp2->next;
			temp->next = indexes[i];
			temp = temp2;
			i = i + 1;
		}
		temp->next = indexes[i];
		this->head = temp;
	}
}
template<class R>
bool S_Link_List<R>::isEmpty()const
{
	if (this->head == nullptr)
		return true;
	return false;
}
template<class R>
void S_Link_List<R>::display_List()const
{
	if (!this->isEmpty())
	{
		Node<R> * callingTemp = this->head;
		while (callingTemp->next != nullptr)
		{
			cout << callingTemp->data << " ";
			callingTemp = callingTemp->next;
		}
		cout << callingTemp->data << "\n";
	}
}
template<class R>
bool S_Link_List<R>::insertBefore(R find, R insert)
{
	if (this->searchEle(find) == true)
	{
		Node<R> * temp = this->head;
		if (this->head->data == find)
		{
			this->head = new Node<R>(insert, temp);
			return true;
		}
		Node<R> * prevEle = temp;
		while (temp->data != find)
		{
			prevEle = temp;
			temp = temp->next;
		}
		prevEle->next = new Node<R>(insert, temp);
		return true;
	}
	return false;
}

template<class R>
int S_Link_List<R>::calcLengthR(Node<R> * ptr)const
{
	if (ptr == nullptr)
		return 0;
	if (ptr->next == nullptr)
		return 1;
	return 1 + calcLengthR(ptr->next);
}
template<class R>
int S_Link_List<R>::getLengthR(const S_Link_List<R> & ref)const
{
	return calcLengthR(ref.head);
}
template<class R>
R S_Link_List<R>::findMinimumR(Node<R> * ptr , R min)const
{
	if (ptr == nullptr || ptr->next == nullptr)
	{
		if (ptr->data < min)
			min = ptr->data;
		return min;
	}
	if (ptr->data < min)
		min = ptr->data;
	return findMinimumR(ptr->next , min);
}
template<class R>
R S_Link_List<R>::getMinimumR(const S_Link_List<R> & ref)const
{
	if (ref.head != nullptr)
	{
		R min = ref.head->data;
		return findMinimumR(ref.head, min);
	}
}
template<class R>
Node<R> * S_Link_List<R>::reverseListR(Node<R> * ref)
{
	if (ref == nullptr)
		return nullptr;
	else if (ref->next == nullptr)
	{
		this->head = ref;
		return ref;
	}
	Node<R> * ptr = reverseListR(ref->next);
	ptr->next = ref;
	ref->next = nullptr;
	return ref;
}
template<class R>
Node<R> * S_Link_List<R>::reverseListRR()
{
	return reverseListR(this->head);
}