#ifndef Stack_H
#define Stack_H
#include<iostream>
using namespace std;
template <typename T>
class Stack {
private:
	T * stackData;
	int capacity;
	int noOfElements;
	int top;
	void resizeStack();
public:
	Stack();
	Stack(const Stack<T> &);
	Stack & operator = (const Stack<T> &);
	~Stack();
	bool isFull();
	bool isEmpty();
	T getTopOfStack()const;
	int getCapacity()const;
	int getNumOfElements()const;
	void pushElement(T);
	T popElement();
	bool isParanthesisValid(char * str)const;
	void displayStack()const;
};
#endif
template<class T>
Stack<T>::Stack() {
	this->capacity = 10;
	this->noOfElements = 0;
	this->stackData = new T[10];
	this->top = -1;
}
template<class T>
Stack<T>::Stack(const Stack & ref) {
	this->capacity = ref.capacity;
	this->noOfElements = ref.noOfElements;
	this->top = this->noOfElements - 1;
	this->stackData = new T[this->capacity];
	for (int i = 0; i < this->noOfElements; i = i + 1)
		this->stackData[i] = ref.stackData[i];
}
template<class T>
Stack<T> & Stack<T>:: operator = (const Stack & ref) {
	if (this != (&ref)) {
		this->capacity = ref.capacity;
		this->noOfElements = ref.noOfElements;
		this->top = this->noOfElements - 1;
		delete[] this->stackData;
		this->stackData = new T[this->capacity];
		for (int i = 0; i < this->noOfElements; i = i + 1)
			this->stackData[i] = ref.stackData[i];
	}
	return (*this);
}
template<class T>
Stack<T>::~Stack() {
	if (this->stackData != NULL) {
		delete[] this->stackData;
		this->stackData = NULL;
	}
	this->capacity = 0;
	this->noOfElements = 0;
	this->top = -1;
}
template<class T>
bool Stack<T>::isEmpty() {
	return this->noOfElements == 0;
}
template<class T>
bool Stack<T>::isFull() {
	return this->noOfElements == this->capacity;
}
template<class T>
int Stack<T>::getCapacity()const {
	return this->capacity;
}
template<class T>
int Stack<T>::getNumOfElements()const {
	return this->noOfElements;
}
template<class T>
T Stack<T>::getTopOfStack()const {
	if (this->noOfElements != 0)
		return this->stackData[this->top];
	else
		cout << "Stack Is Empty...\n";
}
template<class T>
void Stack<T>::resizeStack() {
	T * newStack = new T[this->noOfElements];
	for (int i = 0; i < this->noOfElements; i = i + 1)
		newStack[i] = this->stackData[i];
	this->capacity = this->capacity * 1.5;
	delete[] this->stackData;
	this->stackData = new T[this->capacity];
	for (int i = 0; i < this->noOfElements; i = i + 1)
		this->stackData[i] = newStack[i];
	delete[] newStack;
	newStack = NULL;
}
template<class T>
void Stack<T>::pushElement(T element) {
	if (this->isFull() != true) {
		this->stackData[this->noOfElements++] = element;
		this->top = this->noOfElements - 1;
		//	this->noOfElements = this->noOfElements + 1;
	}
	else {
		this->resizeStack();
		this->stackData[this->noOfElements++] = element;
		this->top = this->noOfElements - 1;
		//	this->noOfElements = this->noOfElements + 1;
	}
}
template<class T>
T Stack<T>::popElement() {
	if (this->isEmpty() != true) {
		this->noOfElements = this->noOfElements - 1;
		this->top = this->noOfElements - 1;
		return this->stackData[this->noOfElements];
	}
	else
		cout << "Stack is Empty...\n";
}
template<class T>
bool Stack<T>::isParanthesisValid(char * str)const {
	Stack obj;
	int index = 0;
	bool isSyntaxValid = true;
	while ((str[index] != '\0') && (isSyntaxValid == true)) {
		if (str[index] == '[' || str[index] == '{' || str[index] == '(')
			obj.pushElement(str[index]);
		else if (str[index] == ']' || str[index] == '}' || str[index] == ')')
		{
			char elementPoped = obj.popElement();
			if ((str[index] == ']' && elementPoped == '[') ||
				(str[index] == '}' && elementPoped == '{') ||
				(str[index] == ')' && elementPoped == '('))
				isSyntaxValid = true;
			else
				isSyntaxValid = false;
		}
		index = index + 1;
	}
	return isSyntaxValid;
}
template<class T>
void Stack<T>::displayStack()const {
	for (int i = 0; i < this->noOfElements; i = i + 1)
		cout << this->stackData[i] << " ";
}
