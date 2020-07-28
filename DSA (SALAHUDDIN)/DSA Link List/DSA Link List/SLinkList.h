#ifndef S_LINK_LIST_H
#define S_LINK_LIST_H
template<typename T>
struct Node
{
	T value;
	Node *ptrToNext;
	Node(T val, Node *ptr)
	{
		value = val;
		ptrToNext = ptr;
	}
};
template<typename T>
class SLinkList
{
	Node<T> *head;
public:
	SLinkList();
	SLinkList(const SLinkList<T> &);
	void addElement(T);
	void removeElement(int);
	int getLength();
	void display();
	SLinkList<T>& reverse();
	SLinkList<T>& sort();
	~SLinkList();
};
#endif // !LINK_LIST_H
