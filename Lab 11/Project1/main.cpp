#include <iostream>
#include "BST.h"
using namespace std;
int main()
{

	BST<int> tree;
	tree.insert(10);
	tree.insert(0);
	tree.insert(30);
	tree.insert(40);
	
	tree.display(0);
	cout << tree.height();
	cout << "\n";
	return 0;
 }