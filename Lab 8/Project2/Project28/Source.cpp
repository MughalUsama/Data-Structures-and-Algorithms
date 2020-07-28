#include <iostream>
#include <fstream>
#include "BinaryTree.h"

using namespace std;

void createTree(BNode<int>* node, fstream& file);

int main()
{
	fstream file;
	file.open("test.txt", ios::in);
	//while (!file.eof())
	{
		int totalSum, currentSum = 0,value;
		char ch;
		bool isFound = false;
		file >> totalSum;
		BinaryTree <int> tree;
		file >> ch;

		file >> ch;

		if (ch!=')')
		{
			file.seekg(-1,ios::cur);
			file >> value;
			tree.setRoot(value);
		
			createTree(tree.getRootNode(), file);
			
			file >> ch;
		}


	}

	return 0;
}
//void createTree()
//{
//
//}
void createTree(BNode<int> * node, fstream &file)
{
	char ch;
	int value;
	file >> ch;
	if (ch==')')
	{
		return;
	}

	if (ch!='(')
	{
		file.seekg(-1, ios::cur);
		file >> value;
		
	}

	file.seekg(-1, ios::cur);
	file >> value;
}