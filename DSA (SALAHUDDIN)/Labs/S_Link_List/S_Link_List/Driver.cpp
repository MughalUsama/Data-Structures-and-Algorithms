#include<iostream>
#include"S_Link_List.h"
#include"Stack.h"
using namespace std;
template<class F>
F findKthLastElement(const S_Link_List<F> & ref, int k)
{
	int length = ref.getLength();
	if ((k > 0 && k <= length) && length != 0)
	{
		Node<int> * temp = ref.getHead();
		int reqInd = length - k;
		while (reqInd != 0)
		{
			temp = temp->next;
			reqInd--;
		}
		return temp->data;
	}
	else
	{
		throw "Out Of Range...\n";
	}
}

template<class F>
void sortLinkList(S_Link_List<F> & ref)
{
	if (ref.getHead() != nullptr && ref.getHead()->next != nullptr)
	{
		bool isSorted = true;
		Node<F> * temp = ref.getHead();
		F tempEle;
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
				temp = ref.getHead();
				isSorted = true;
			}
		}
	}
}

template<class F>
bool isListPalindrome(const S_Link_List<F> & ref)
{
	if (ref.getHead() == nullptr)
		return false;
	else if (ref.getHead()->next == nullptr)
		return true;
	else
	{
		int i = 0, length = ref.getLength();
		Node<F> * temp = ref.getHead();
		char * string = new char[length / 2];
		for (i = 0; i != length / 2; i = i + 1)
		{
			string[i] = temp->data;
			temp = temp->next;
		}
		if (length % 2 == 1)
			temp = temp->next;
		for (i = (length / 2) - 1; i >= 0; i = i - 1)
		{
			if (temp->data != string[i])
				return false;
			temp = temp->next;
		}
		return true;
	}
}

template<class F>
F getMiddleElement(const S_Link_List<F> & ref)
{
	if (ref.getHead() != nullptr)
	{
		Node<F> * temp1 = ref.getHead();
		Node<F> * temp2 = ref.getHead();
		while (temp2->next != nullptr)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
			if (temp2->next != nullptr)
			{
				temp2 = temp2->next;
			}
		}
		return temp1->data;
	}
	else
		throw "List is Empty\n";
}

template<class F>
void partitioning(S_Link_List<F> & ref, int value)
{
	if (ref.searchEle(value) == true)
	{
		if (ref.head != nullptr && ref.head->next != nullptr)
		{
			Stack<F> stack1;
			Stack<F> stack2;
			Stack<F> stack3;
			Node<F> * temp = ref.getHead();
			while (temp->next != nullptr)
			{
				if (temp->data < value)
					stack1.pushElement(temp->data);
				else if (temp->data > value)
					stack2.pushElement(temp->data);
				else
					stack3.pushElement(temp->data);
				temp = temp->next;
			}
			if (temp->data < value)
				stack1.pushElement(temp->data);
			else if (temp->data > value)
				stack2.pushElement(temp->data);
			else
				stack3.pushElement(temp->data);
			Node<F> * temp2 = ref.getHead();
			F var;
			while (temp2->next != nullptr)
			{
				if (stack1.isEmpty() == false)
				{
					var = stack1.popElement();
					temp2->data = var;
				}
				else if (stack3.isEmpty() == false)
				{
					var = stack3.popElement();
					temp2->data = var;
				}
				else
				{
					var = stack2.popElement();
					temp2->data = var;
				}
				temp2 = temp2->next;
			}
			if (stack1.isEmpty() == false)
			{
				var = stack1.popElement();
				temp2->data = var;
			}
			else if (stack3.isEmpty() == false)
			{
				var = stack3.popElement();
				temp2->data = var;
			}
			else
			{
				var = stack2.popElement();
				temp2->data = var;
			}
		}
	}
}

template<class F>
void generateLoop(S_Link_List<F> & ref , int loopPoint)
{
	Node<int> * temp = ref.getHead();
	Node<int> * temp2 = nullptr;
	int i = 1;
	while (temp->next != nullptr)
	{
		if (i == loopPoint)
		{
			temp2 = temp;
		}
		i++;
		temp = temp->next;
	}
	if (i == loopPoint)
	{
		temp2 = temp;
	}
	temp->next = temp2;
}

template<class F>
void findAndBreakLoop(S_Link_List<F> & ref)
{
	if (ref.head->next == ref.head)
		ref.head->next = nullptr;
	else
	{
		Node<F> * temp1 = ref.head;
		bool isLoopBroken = false;
		while (temp1->next != nullptr && isLoopBroken == false)
		{
			Node<F> * temp2 = ref.head;
			while (temp2->next != temp1->next && isLoopBroken == false)
			{
				if (temp1->next == temp2)
				{
					temp1->next = nullptr;
					isLoopBroken = true;
				}
				temp2 = temp2->next;
			}
			if (temp2->next == temp1->next && temp1 != temp2)
			{
				temp1->next = nullptr;
				isLoopBroken = true;
			}
			if (isLoopBroken == false)
				temp1 = temp1->next;
		}
	}
}

int main()
{
	S_Link_List<int> list;
	list.addNewNode(18);
	list.addNewNode(19);
	list.addNewNode(20);
	list.addNewNode(21);
	list.addNewNode(23);
	list.addNewNode(22);
	list.addNewNode(2);
	list.display_List();
	list.reverseListRR();
	list.display_List();


	//generateLoop<int>(list, 1);                                                // find and break loop
	//findAndBreakLoop<int>(list);
	//list.display_List();


	//partitioning(list, 18);                                                  // partitioning
	//list.display_List();


	//list.insertBefore(2, 1);                                               // insert before
	//list.display_List();


	//int k = 3;                                                             // kth last element
	//try
	//{
	//	cout << k <<"th Last Element : "<<findKthLastElement<int>(list, k);
	//}
	//catch (char * message)
	//{
	//	cout << message;
	//}
	

	//sortLinkList<int>(list);                                               // sort link list
	//list.display_List();


	//S_Link_List<char> strList;                                               // is palindrome
	//strList.addNewNode('1');
	//strList.addNewNode('2');
	//strList.addNewNode('0');
	//strList.addNewNode('2');
	//strList.addNewNode('1');
	//strList.addNewNode('3');
	//strList.addNewNode('1');
	//strList.addNewNode('3');
	//strList.addNewNode('0');
	//strList.addNewNode('2');
	//strList.addNewNode('1');
	//strList.display_List();
	//cout<<isListPalindrome<char>(strList);


	/*try                                                                        // get middle element
	{
		cout << getMiddleElement<int>(list);
	}
	catch (char * message)
	{
		cout << message;
	}*/


	cout << "\n\n\n";
	return 0;
}