#include <iostream>
#include "MinHeap.h"
using namespace std;


int main()
{
	try
	{
		MinHeap<int> heap(12);
		heap.insert(16);							//				1								
		heap.insert(14);								//	2				3
		heap.insert(10);			//					4		5		6		7
		heap.insert(8);			//				8	 9	10	 11	  12 
		heap.insert(7);
		heap.insert(9);
		heap.insert(3);
		heap.insert(2);
		heap.insert(4);
		heap.insert(1);
		//heap.insert(11);
		//heap.insert(12);

		//cout << heap.extractMin();
		//cout << heap.getMin();
		heap.display1();
		cout << "\n";
		//heap.deleteKey(4);
		//cout << heap.parent(0);
		heap.display();
	}
	catch (const char * errorMsg)
	{
		cout << errorMsg;
	}
	cout << "\n";
	return 0;
}