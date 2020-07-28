#ifndef  BINARY_TREE_H
#define BINARY_TREE_H

#include<iostream>
#include "Queue.h"
#include "Queue.cpp"
#include <cmath>

using namespace std;


template<typename T>
class BNode
{
	public:
		T data;
		BNode<T> *right;
		BNode<T> *left;
		BNode()
		{
			left = right = nullptr;
		}
		BNode(T x)
		{
			data = x;
			left = right = nullptr;
		}
};



template<typename T>
class BinaryTree
{
	BNode<T> *root;

			/*Helper Functions*/
	void deleteTreeHelper(BNode<T> * &Node);
	void setLeftHelper(BNode<T> * Node, T parent, T child);
	void setRightHelper(BNode<T> * Node, T parent, T child);
	void displayHelper(BNode<T> * Node);
	void getParentHelper(BNode<T>* Node, T child, BNode<T> * & parent);
	void removeHelper(BNode<T>* & Node,T nodeValue);
	bool isInternalNodeHelper(BNode<T>* Node,T nodeValue);
	bool isExternalNodeHelper(BNode<T>* Node,T nodeValue);
	bool findNodeHelper(BNode<T>*& Node, T nodeValue);
	void findNodeSiblingsHelper(BNode<T>* Node, T nodeValue, BNode<T>*& sibling);
	void displayDescendentsHelpers(BNode<T>* Node, T nodeValue);
	void heightOfTreeHelper(BNode<T>* Node, int height, int &maxHeight);
	void postOrderHelper(BNode<T>* Node);
	void inOrderHelper(BNode<T>* Node);
	void preOrderHelper(BNode<T>* Node);
	void operatorEqualHelper(BNode<T>* node, BNode<T>* &newNode);

public:
	BinaryTree(); 
	~BinaryTree(); 
	T getRoot(); 
	void setRoot(T); 
	void setLeftChild(T parent, T Child); 
	void setRightChild(T parent, T Child); 
	T getParent(T node); 
	void remove(T Node); 

	bool isInternalNode(T node); 
	bool isExternalNode(T node); 

	bool findNode(T nodeValue); 
	T findNodeSiblings(T node); 

	void displayDescendents(T node);	
	int heightOfTree();	
	void preOrder();	
	void postOrder();	
	void inOrder();		
	void levelOrder();	

	BinaryTree<T> & operator=(const BinaryTree<T> & tree);
	void displayParenthesizedView(); 


};

template<typename T>
 BinaryTree<T>::BinaryTree()
{
	this->root = nullptr;
}

template<typename T>
 BinaryTree<T>::~BinaryTree()
{
	deleteTreeHelper(this->root);
}

template<typename T>
void BinaryTree<T>::deleteTreeHelper(BNode<T>* & node)
{
	if (node!=nullptr)
	{
		if (node->right!=nullptr)
		{
			deleteTreeHelper(node->right);
		}
		if (node->left!=nullptr)
		{
			deleteTreeHelper(node->left);
		}
		delete node;
		node = nullptr;
	}

}

template<typename T>
void BinaryTree<T>::setLeftHelper(BNode<T>* Node, T parent, T child)
{
	if (Node == nullptr)
	{
		return;
	}
	else if (Node->data==parent)
	{
		if (Node->left != nullptr)
		{
			Node->left->data = child;
		}
		else
		{
			Node->left = new BNode<T>;
			Node->left->data = child;
		}
		return;
	}
	
	setLeftHelper(Node->left, parent, child);
	setLeftHelper(Node->right, parent, child);
}

template<typename T>
void BinaryTree<T>::setRightHelper(BNode<T>* Node, T parent, T child)
{
	if (Node == nullptr)
	{
		return;
	}
	else if (Node->data == parent)
	{
		if (Node->right != nullptr)
		{
			Node->right->data = child;
		}
		else
		{
			Node->right= new BNode<T>;
			Node->right->data = child;
		}
		return;
	}
	setRightHelper(Node->left, parent, child);
	setRightHelper(Node->right, parent, child);
}

template<typename T>
void BinaryTree<T>::displayHelper(BNode<T>* Node)
{
	if (Node != nullptr)
	{
		cout << Node->data ;
	}
	else
	{
		return;
	}
	if (Node->left!=nullptr)
	{
		cout << "(";
		displayHelper(Node->left);
		cout << ")";
	}

	if (Node->right != nullptr)
	{
		cout << "(";
		displayHelper(Node->right);
		cout << ")";
	}

}

template<typename T>
void BinaryTree<T>::getParentHelper(BNode<T>* Node, T child, BNode<T>* & parent)
{
	if (Node == nullptr)
	{
		return;
	}
	if (Node->left != nullptr && Node->left->data == child)
	{
		parent = new BNode<T>;
		parent->data = Node->data;
		return;
	}
	if (Node->right != nullptr && Node->right->data == child)
	{
		parent = new BNode<T>;
		parent->data = Node->data;
		return;
	}

	getParentHelper(Node->left, child, parent);

	if (parent==nullptr)
	{
		getParentHelper(Node->right, child, parent);
	}
}

template<typename T>
void BinaryTree<T>::removeHelper(BNode<T>* & Node, T nodeValue)
{
	if (Node==nullptr)
	{
		return;
	}
	if (Node->data==nodeValue)
	{
		deleteTreeHelper(Node);
		Node = nullptr;
		return;
	}
	removeHelper(Node->left, nodeValue);
	removeHelper(Node->right, nodeValue);

}

template<typename T>
bool BinaryTree<T>::isInternalNodeHelper(BNode<T>* Node, T nodeValue)
{
	bool isInternal=false;
	if (Node==nullptr)
	{
		return false;
	}
	if (Node->data==nodeValue)
	{
		if (Node->left!=nullptr || Node->right!=nullptr)
		{
			return true;
		}
		return false;
	}
	isInternal = isInternalNodeHelper(Node->left, nodeValue);
	if (isInternal==true)
	{
		return true;
	}
	isInternal = isInternalNodeHelper(Node->right, nodeValue);
	return isInternal;
}

template<typename T>
bool BinaryTree<T>::isExternalNodeHelper(BNode<T>* Node, T nodeValue)
{
	bool isExternal = false;

	if (Node == nullptr)
	{
		return false;
	}

	if (Node->data == nodeValue)
	{

		if (Node->left == nullptr && Node->right == nullptr)
		{

			return true;
		}

		return false;
	}
	isExternal = isExternalNodeHelper(Node->left, nodeValue);
	if (isExternal == true)
	{
		return true;
	}
	isExternal = isExternalNodeHelper(Node->right, nodeValue);
	return isExternal;
}

template<typename T>
bool BinaryTree<T>::findNodeHelper(BNode<T>*& Node, T nodeValue)
{
	bool isFound = false;

	if (Node == nullptr)
	{
		return false;
	}

	if (Node->data == nodeValue)
	{
		return true;
	}

	isFound = findNodeHelper(Node->left, nodeValue);
	
	if (isFound == true)
	{
		return true;
	}
	isFound = findNodeHelper(Node->right, nodeValue);
	return isFound;
}

template<typename T>
void BinaryTree<T>::findNodeSiblingsHelper(BNode<T>* Node, T nodeValue, BNode<T>*& sibling)
{
	if (Node == nullptr)
	{
		return;
	}

	if (Node->left != nullptr && Node->left->data == nodeValue)
	{
		if(Node->right != nullptr)
		{
			sibling = new BNode<T>;
			sibling->data = Node->right->data;
			return;
		}
		throw "\n No sibling found! \n";
	}
	if (Node->right != nullptr && Node->right->data == nodeValue)
	{
		if (Node->left != nullptr) 
		{

			sibling = new BNode<T>;
			sibling->data = Node->left->data;
			return;
		}
		throw "\n No sibling found! \n";
	}

	findNodeSiblingsHelper(Node->left, nodeValue, sibling);

	if (sibling== nullptr)
	{

		findNodeSiblingsHelper(Node->right, nodeValue, sibling);
	}
}

template<typename T>
void BinaryTree<T>::displayDescendentsHelpers(BNode<T>* Node, T nodeValue)
{
	if (Node==nullptr)
	{
		return;
	}
	if (Node->data==nodeValue)
	{
		displayHelper(Node);
		return;
	}
	displayDescendentsHelpers(Node->left, nodeValue);
	displayDescendentsHelpers(Node->right, nodeValue);

}

template<typename T>
void BinaryTree<T>::heightOfTreeHelper(BNode<T>* Node, int height, int& maxHeight)
{
	if (Node==nullptr)
	{
		return;
	}
	height++;
	if (height>maxHeight)
	{
		maxHeight = height;
	}
	heightOfTreeHelper(Node->left, height, maxHeight);
	heightOfTreeHelper(Node->right, height, maxHeight);
}

template<typename T>
void BinaryTree<T>::postOrderHelper(BNode<T>* Node)
{
	if (Node == nullptr)
	{
		return;
	}
	if (Node->left != nullptr)
	{
		postOrderHelper(Node->left);
		cout << " ";
	}

	if (Node->right != nullptr)
	{
		postOrderHelper(Node->right);
		cout << " ";
	}
	cout << Node->data;

}

template<typename T>
void BinaryTree<T>::inOrderHelper(BNode<T>* Node)
{
	if (Node == nullptr)
	{
		return;
	}
	if (Node->left != nullptr)
	{
		inOrderHelper(Node->left);
	}

	cout << Node->data << " ";


	if (Node->right != nullptr)
	{
		inOrderHelper(Node->right);
	}
}

template<typename T>
void BinaryTree<T>::preOrderHelper(BNode<T>* Node)
{
	if (Node == nullptr)
	{
		return;
	}
	cout << Node->data << " ";
	if (Node->left != nullptr)
	{
		preOrderHelper(Node->left);
		
	}

	if (Node->right != nullptr)
	{
		preOrderHelper(Node->right);

	}
}

template<typename T>
void BinaryTree<T>::operatorEqualHelper(BNode<T>* node, BNode<T>* &newNode)
{
	if (node==nullptr)
	{
		return;
	}
	newNode = new BNode<T>;
	newNode->data = node->data;
	operatorEqualHelper(node->left,newNode->left);
	operatorEqualHelper(node->right, newNode->right);
}

template<typename T>
T BinaryTree<T>::getRoot()
{
	return this->root->data;
}

template<typename T>
void BinaryTree<T>::setRoot(T value)
{
	if (this->root==nullptr)
	{
		this->root = new BNode<T>;
		this->root->data = value;
	}
	else
	{
		this->root->data = value;
	}
}

template<typename T>
void BinaryTree<T>::setLeftChild(T parent, T child)
{
	setLeftHelper(this->root, parent, child);
}

template<typename T>
void BinaryTree<T>::setRightChild(T parent, T child)
{
	setRightHelper(this->root, parent, child);
}

template<typename T>
 T BinaryTree<T>::getParent(T node)
{
	 BNode<T> *parent = nullptr;
	 if (this->root->data==node)
	 {
		 throw "\n Root node does not have a parent! \n";
	 }
	 getParentHelper(this->root, node,parent);
	 if (parent!=nullptr)
	 {
		 return parent->data;
	 }
	 throw "\n Node not found! \n";
}

template<typename T>
void BinaryTree<T>::remove(T node)
{
	 removeHelper(this->root, node);
}

template<typename T>
 bool BinaryTree<T>::isInternalNode(T node)
{
	return isInternalNodeHelper(this->root,node);
}

template<typename T>
 bool BinaryTree<T>::isExternalNode(T node)
{
	return isExternalNodeHelper(this->root,node);
}

template<typename T>
 bool BinaryTree<T>::findNode(T nodeValue)
{
	return findNodeHelper(this->root,nodeValue);
}

template<typename T>
 T BinaryTree<T>::findNodeSiblings(T node)
{
	 BNode<T>* sibling = nullptr;
	 if (this->root->data==node)
	 {
		 throw "\nRoot has no siblings\n";
	 }
	findNodeSiblingsHelper(this->root,node,sibling);
	if (sibling==nullptr)
	{
		throw "\nNode not found\n";
	}
	return sibling->data;
}

template<typename T>
void BinaryTree<T>::displayDescendents(T node)
{
	 displayDescendentsHelpers(this->root, node);
}

template<typename T>
 int BinaryTree<T>::heightOfTree()
{
	 if (this->root==nullptr)
	 {
		 return 0;
	 }
	int treeHeight = 0;
	heightOfTreeHelper(this->root, -1, treeHeight);
	return treeHeight;
}

template<typename T>
void BinaryTree<T>::preOrder()
{
	preOrderHelper(this->root);
}

template<typename T>
void BinaryTree<T>::postOrder()
{
	 postOrderHelper(this->root);
}

template<typename T>
void BinaryTree<T>::inOrder()
{
	 inOrderHelper(this->root);
}

template<typename T>
void BinaryTree<T>::levelOrder()
{
	Queue <BNode<T>*> queue(2*pow(heightOfTree(),2)); // to get maximum nodes at last 2 levels of tree and make queue of this size 
	queue.enqueue(this->root);
	while (!queue.isEmpty())
	{
		BNode <T>* temp = queue.getFront();
		cout << temp->data;
		queue.dequeue();
		if (temp->left!=nullptr)
		{
			queue.enqueue(temp->left);
		}
		if (temp->right!= nullptr)
		{
			queue.enqueue(temp->right);
		}
	}
}

template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& tree)
{
	this->~BinaryTree();
	operatorEqualHelper(tree.root,this->root);
	return *this;
}

template<typename T>
void BinaryTree<T>::displayParenthesizedView()
{
	 displayHelper(this->root);
}



#endif // ! BINARY_TREE_H
