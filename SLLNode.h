#ifndef SLL_NODE_H
#define SLL_NODE_H

template<class T>
struct Node
{
	T value;
	Node * ptrToNextNode;
	//constructor 
	Node(T val, Node * prtToNextNode = nullptr)
	{
		this->value = val;
		this->ptrToNextNode = prtToNextNode;
	}
};
#endif // !SLL_NODE_H
