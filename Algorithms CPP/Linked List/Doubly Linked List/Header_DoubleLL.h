#pragma once
#include <iostream>
#include <string>
using namespace std;

// forward declaration of template class List
template <class T>
class DList;

template <class T>
class DNode
{
	friend DList<T>;
	T data;
	DNode<T>* next;
	DNode<T>* prev;
	DNode(T inData, DNode* nPtr = NULL, DNode* pPtr = NULL);
};

template <class T>
class DList
{
	DNode<T>* head;
	DNode<T>* tail;
public:
	DList() :head(NULL), tail(NULL)//default counstructor
	{

	}
	DList(const DList& copyLL);
	~DList();
	bool isEmpty();
	void setHead(DNode<T>* hhead);
	void setTail(DNode<T>* Tail);
	DNode<T>* getHead();
	DNode<T>* getTail();
	void insertAtHead(T value);
	void insertAtTail(T value);
	bool deleteAtHead();
	bool deleteAtTail();
	void printList();
	DNode<T>* getNode(int n);
	bool insertAfter(T value);
	bool deleteAfter(T value);
	int getLength();
	DNode<T>* search(T key);
	DNode<T>* nodeSearch(T x);

};
