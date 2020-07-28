#ifndef SLINKEDLISTS_H
#define SLINKEDLISTS_H

template<class T>
class SLinkedLists
{
private:

	struct Node
	{
		T value;
		Node* next;
	};

	Node * head;

public:
	SLinkedLists();
	~SLinkedLists();
};

#endif

