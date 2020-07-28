#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{



	try
	{
		BinaryTree<int> tree;
		
		tree.setRoot(1);
		
		tree.setLeftChild(1, 2);
		tree.setRightChild(1, 3);

		tree.setLeftChild(2, 4);
		tree.setRightChild(2, 5);
		tree.setLeftChild(3, 6);
		tree.setRightChild(3, 7);


		
		tree.displayParenthesizedView();

		cout << "\n";

		 tree.inOrder();

	}
	catch (const char * errMsg)
	{
		cout << errMsg;
	}

	
	cout << "\n";
	return 0;
}