#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <typename T>
class BSTNode
{
	public:
		BSTNode();
		BSTNode(T);

		T data;

		BSTNode<T>* left, * right;
};
template<typename T>
BSTNode<T>::BSTNode()
{
	left = right = nullptr;
}

template<typename T>
BSTNode<T>::BSTNode(T value)
{
	left = right = nullptr;
	data = value;
}

//template<typename T>
//BSTNode<T>::~BSTNode()
//{
//
//}


template <typename T>
class BST
{
private:
	BSTNode<T>* root;
	void displayAscending(BSTNode<T>*);
	void displayDescending(BSTNode<T>*);
	bool insertHelper(BSTNode<T>* &node,T value);
	bool removeHelper(BSTNode<T>*& node, T value);
	void clearHelper(BSTNode<T>*& node);
	bool findHelper(BSTNode<T>* node, T value);
	void heightOfTreeHelper(BSTNode<T>* node, int height, int& maxHeight);
	void sizeHelper(BSTNode<T>*& node, int size);
public:
	BST();
	~BST();
	bool empty();
	bool insert(T);
	bool remove(T);
	void clear();
	int height();
	int size();
	bool find(T);
	void display(bool =true);
};





template<typename T>
 void BST<T>::displayAscending(BSTNode<T>* node)
{
	 if (node == nullptr)
	 {
		 return;
	 }
	 if (node->left != nullptr)
	 {
		 displayAscending(node->left);
	 }

	 cout << node->data << " ";

	 if (node->right != nullptr)
	 {
		 displayAscending(node->right);
	 }
}

template<typename T>
 void BST<T>::displayDescending(BSTNode<T>* node)
{
	 if (node == nullptr)
	 {
		 return;
	 }
	 if (node->right != nullptr)
	 {
		 displayDescending(node->right);
	 }

	 cout << node->data << " ";

	 if (node->left != nullptr)
	 {
		 displayDescending(node->left);
	 }
}

 template<typename T>
 bool BST<T>::insertHelper(BSTNode<T>*& node, T value)
 {

	 if (node==nullptr)
	 {
		 node = new BSTNode <T>;
		 node->data=value;
		 return true;
	 }
	 if (node->data > value)
	 {
		 return insertHelper(node->left, value);
	 }
	 else if (node->data < value)
	 {
		 return insertHelper(node->right, value);
	 }
	 else
	 {
		 return false;
	 }
 }

 template<typename T>
 bool BST<T>::removeHelper(BSTNode<T>*& node, T value)
 {
	 if (node=nullptr)
	 {
		 return false;
	 }
	 if (node->data<value)
	 {
		 return removeHelper(node->right);
	 }
	 else if(node->data>value)
	 {
		return removeHelper(node->left);
	 }
	 if (node->left->data==value && node->left==nullptr && node->right==nullptr)
	 {
		 delete node->left;
		 node->left = nullptr;
	 }
	 if (node->right->data == value && node->right->right == nullptr && node->right->left == nullptr)
	 {
		 delete node->right;
		 node->right = nullptr;
	 }
	 if (node->right->data == value )
	 {
		 if (node->right->right == nullptr && node->right->left != nullptr)
		 {
			
		 }
		 else if(node->right->right != nullptr && node->right->left == nullptr)
		 {

		 }
		
	 }
	 if (node->left->data == value && node->left->right == nullptr && node->left->left == nullptr)
	 {

	 }
	 
 }

template<typename T>
BST<T>::BST()
{
	this->root = nullptr;
}

template<typename T>
BST<T>::~BST()
{
	this->clear();
}
template<typename T>
bool BST<T>::empty()
{
	if (this->root==nullptr)
	{
		return true;
	}
	return false;
}
template<typename T>
 bool BST<T>::insert(T value)
{
	 if (this->root==nullptr)
	 {
		 this->root = new BSTNode<T>(value);
		 return true;
	 }
	 else
	 {
		 return insertHelper(this->root,value);
	 }
}
template<typename T>
 bool BST<T>::remove(T value)
{
	 if(this->root==nullptr)
	 {
		 return false;
	 }
	return removeHelper(this->root,value);
}
template<typename T>
 void BST<T>::clear()
{
	 clearHelper(this->root);
}
template<typename T>
 int BST<T>::height()
{
	 if (this->root == nullptr)
	 {
		 return 0;
	 }
	 int treeHeight = 0;
	 heightOfTreeHelper(this->root, -1, treeHeight);
	 return treeHeight;
}
template<typename T>
 int BST<T>::size()
{
	int size;
	sizeHelper(this->root, size);
	return size;
}
template<typename T>
 bool BST<T>::find(T value)
{
	return findHelper(this->root);
}
template<typename T>
 void BST<T>::display(bool value)
{
	if (value)
	{
		displayAscending(this->root);
	}
	else
	{
		displayDescending(this->root);
	}
}


 template<typename T>
 void BST<T>::clearHelper(BSTNode<T>*& node)
 {
	 if (node != nullptr)
	 {
		 if (node->right != nullptr)
		 {
			 clearHelper(node->right);
		 }
		 if (node->left != nullptr)
		 {
			 clearHelper(node->left);
		 }
		 delete node;
		 node = nullptr;
	 }
 }

 template<typename T>
 bool BST<T>::findHelper(BSTNode<T>* node, T value)
 {
	 if (node == nullptr)
	 {
		 return false;
	 }
	 if (node->data == value)
	 {
		 return false;
	 }
	 else if (node->data > value)
	 {
		 return findHelper(node->left);
	 }
	 else if (node->data < value)
	 {
		 return findHelper(node->right);
	 }
 }
 template<typename T>
 void BST<T>::heightOfTreeHelper(BSTNode<T>* Node, int height, int& maxHeight)
 {
	 if (Node == nullptr)
	 {
		 return;
	 }
	 height++;
	 if (height > maxHeight)
	 {
		 maxHeight = height;
	 }
	 heightOfTreeHelper(Node->left, height, maxHeight);
	 heightOfTreeHelper(Node->right, height, maxHeight);
 }

 template<typename T>
 void BST<T>::sizeHelper(BSTNode<T>* &node, int size)
 {
	 if (node == nullptr)
	 {
		 return;
	 }
	 if (node->right != nullptr)
	 {
		 sizeHelper(node->right, size);
	 }

	 size++;

	 if (node->left != nullptr)
	 {
		sizeHelper(node->left);
	 }
 }


#endif // !
