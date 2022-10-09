#include <iostream>
#include <string>
#include <vector>
#include "Header_DoubleLL.h"

template <class T>
DNode<T>::DNode(T inData, DNode* nPtr, DNode* pPtr)//constructor
{
	data = inData;
	next = nPtr;
	prev = pPtr;
}

template <class T>
DList<T>::DList<T>(const DList& copyLL)//copy counstructor
{
	if (copyLL.head == NULL)//when list is empty
	{
		head = tail = NULL;
	}
	else
	{

		head = new DNode<T>(copyLL.head->data);
		DNode<T>* transV = head;
		DNode<T>* tHead = copyLL.head;
		while (tHead->next != NULL)//traversing the list and coping
		{
			transV->next = new DNode<T>(tHead->next->data);
			transV->prev = tHead->prev;
			tHead = tHead->next;
			transV = transV->next;
		}
	}

}
template<class T>
DList<T>::~DList()//destructor
{
	DNode<T>* temp = head;
	while (temp)//deleting each node
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}
template <class T>
bool DList<T>::isEmpty()
{
	return head == NULL;//no value in list
}
template<class T>
DNode<T>* DList<T> ::nodeSearch(T key)
{
	if (!isEmpty())
	{
		int flag = 0;
		DNode<T>* temp = head;
		while (temp)//to reach the node->data equal to x
		{
			if (temp->data == key)
			{
				flag = 1;
				break;
			}
			else
				temp = temp->next;
		}
		if (flag == 0)//when value of x doesnt exists in any of the node
		{
			DNode<T>* newNode = new DNode<T>(key);
			return newNode;
		}
		if (temp)
		{
			return temp;
		}
	}
	else
	{
		cout << "List is empty! No node exists." << endl;
		DNode<T>* newNode = new DNode<T>(key);
		return newNode;
	}
}
template <class T>
void DList<T> ::setHead(DNode<T>* hhead)
{
	int flag = 0;
	DNode<T>* temp = head;
	while (temp)//to reach the node->data equal to x
	{
		if (hhead == head)
		{
			flag = 1;
			cout << "Entered node is already placed at head"<<endl;
			break;
		}
		if (hhead == tail)//if we have to place tail as head
		{
			flag = 1;
			insertAtHead(hhead->data);
			deleteAtTail();
			break;
		}
		if (temp==hhead)
		{
			flag = 1;
			DNode<T>* newNode = new DNode<T>(hhead->data);
			DNode<T>* delNode = temp;
			(temp->prev)->next = temp->next;
			(temp->next)->prev = temp->prev;
			delete delNode;
			
			if (isEmpty())//when list is empty ,only the newNode will exist
			{
				head = tail = newNode;
			}
			else
			{
				//place the selected node at head
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
				head->prev = NULL;
			}
			break;
		}
		else
			temp = temp->next;
	}
	if (flag==0)
	{
		if (isEmpty())//when list is empty ,only the newNode will exist
		{
			head = tail = hhead;
		}
		else
		{
			hhead->next = head;
			head->prev = hhead;
			head = hhead;
			head->prev = NULL;
		}
	}
}
template <class T>
void DList<T> ::setTail(DNode<T>* ttail)
{
	int flag = 0;
	DNode<T>* temp = head;
	while (temp)//to reach the node->data equal to x
	{
		if (ttail == tail)
		{
			flag = 1;
			cout << "Entered node is already placed at tail" << endl;
			break;
		}
		if (ttail == head)//if we have to place head as tail
		{
			flag = 1;
			insertAtTail(ttail ->data);
			deleteAtHead();
			break;
		}
		if (temp == ttail)
		{
			flag = 1;
			DNode<T>* newNode = new DNode<T>(ttail->data);
			DNode<T>* delNode = temp;
			(temp->prev)->next = temp->next;
			(temp->next)->prev = temp->prev;
			delete delNode;

			if (isEmpty())//when list is empty ,only the newNode will exist
			{
				head = tail = newNode;
			}
			else
			{
				//place the selected node at tail
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
				tail->next = NULL;
			}
			break;
		}
		else
			temp = temp->next;
	}
	if (flag == 0)
	{
		if (isEmpty())//when list is empty ,only the newNode will exist
		{
			head = tail = ttail;
		}
		else
		{
			tail->next = ttail;
			ttail->prev = tail;
			tail = ttail;
			tail->next = NULL;
		}
	}
}

template <class T>
DNode<T>* DList<T> ::getHead()
{
	return head;
}
template <class T>
DNode<T>* DList<T> ::getTail()
{
	return tail;
}
template <class T>
void DList<T> ::insertAtHead(T value)//inserts a node carrying data ,in frontend of Linked List
{
	DNode<T>* newNode = new DNode<T>(value);

	if (isEmpty())//when list is empty ,only the newNode will exist
	{
		head = tail = newNode;
		
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		head->prev = NULL;
	}
}

template <class T>
void DList<T>::insertAtTail(T value)//inserts a node carrying data ,in last end of Linked List
{
	DNode<T>* newNode = new DNode<T>(value);

	if (isEmpty())//when list is empty ,only the newNode will exist
	{
		head = tail = newNode;
		
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		tail->next = NULL;
	}
}
template<class T>
bool DList<T>::deleteAtHead()//deletes the head-node of linked list
{
	if (!isEmpty())
	{
		DNode<T>* temp = head;
		head->prev = NULL;
		head = head->next;
		delete temp;
		if (isEmpty())//when only one node was in the list and that is deleted ,then we have to point tail to NULL showing the list is empty now
		{
			tail = NULL;
		}
		return true;
	}
	return false;//no node to delete when list is empty
}
template<class T>
bool DList<T>::deleteAtTail()//deletes the tail-node of linked list
{
	if (!isEmpty())
	{

		DNode<T>* temp = tail;
		tail = tail->prev;
		tail->next = NULL;

		delete temp;
		if (isEmpty())//when only one node was in the list and that is deleted ,then we have to point head to NULL showing the list is empty now
		{
			head = NULL;
		}
		return true;
	}
	return false;//no node to delete when list is empty
}
template <class T>
void DList<T>::printList()//prints the linking of all nodes
{
	DNode<T>* temp = head;
	cout << "NULL" << " <-- ";
	while (temp)//untill NULL pointer comes
	{
		cout << temp->data << " <-- --> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;//tail points towards nothing/NULL
}
template<class T>
DNode<T>* DList<T> ::search(T key)
{
	if (!isEmpty())
	{
		int flag = 0;
		DNode<T>* temp = head;
		while (temp)//to reach the node->data equal to x
		{
			if (temp->data == key)
			{
				flag = 1;
				break;
			}
			else
				temp = temp->next;
		}
		if (flag == 0)//when value of x doesnt exists in any of the node
		{
			cout << "No such node exists.";
			return NULL;
		}
		if (temp)
		{
			if (temp == tail)//when value of x is equal to data of tail
			{
				cout << "Tail pointer points towards NULL value";
				return NULL;
			}

			return temp->next;//pointer which shows link
		}
	}
	else
	{
		cout << "List is empty! No node exists." << endl;
		return NULL;
	}

}

template <class T>
DNode<T>* DList<T>::getNode(int n)//to get the address of nth node
{

	if (!isEmpty())
	{
		int count = 1;
		DNode<T>* temp = head;
		while (temp->next != NULL)//calculating the count of nodes
		{
			temp = temp->next;
			count++;
		}
		if (n > count)//when passed value is greater than the count of nodes->address of tail will be displayed (as demanded)
		{
			return tail;
		}
		else
		{
			temp = head;
			count = 1;
			while (n != count)//finding the exact node to print its address
			{
				temp = temp->next;
				count++;
			}
			return temp;
		}
	}

	return NULL;//no node exists
}

template <class T>
bool DList<T>::insertAfter(T value)
{
	DNode<T>* temp = head;
	while (temp)//to reach the node->data equal to key
	{
		if (temp->data == value)
			break;
		else
			temp = temp->next;
	}
	int set_data;
	cout << "Enter the value you want to insert after a node: ";
	cin >> set_data;
	if (temp)//inserting the next node
	{
		DNode<T>* newNode = new DNode<T>(set_data);
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next = newNode;

		temp->next->prev = newNode;
		if (temp == tail)
			insertAtTail(set_data);
		return true;
	}
	else
		return false;//no node exists
}

template<class T>
bool DList<T> ::deleteAfter(T value)
{
	if (!isEmpty())
	{
		DNode<T>* temp = head;
		while (temp)//to reach the node->data equal to key
		{
			if (temp->data == value)
				break;
			else
				temp = temp->next;
		}
		if (temp)
		{
			if (temp == tail)//when key node is tail
			{
				cout << "No node exists after tail ";
				return false;
			}
			else
			{
				if (temp->next == tail)////when we have to delete the tail
				{
					deleteAtTail();
				}
				else//deleting random after node
				{
					DNode<T>* delNode = temp->next;
					temp->next = (temp->next)->next;
					(temp->next)->prev = temp;
					delete delNode;
				}

				return true;
			}
			return true;
		}
		else
			return false;//no such node exists
	}
	else
	{
		return false;//no node exists
	}
}
template<class T>
int DList<T> ::getLength()
{
	int count = 0;
	if (!isEmpty())
	{
		count = 1;
		DNode<T>* temp = head;
		while (temp->next != NULL)//calculating the number of nodes
		{
			temp = temp->next;
			count++;
		}
		return count;
	}
	return count;//no node exists
}


int main()
{
	DList<int> list;
	int inputVal, key;

	//INSERTION AT HEAD
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter a value to insert at head: ";
		cin >> inputVal;
		list.insertAtHead(inputVal);
	}

	//INSERTION AT TAIL
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter a value to insert at tail: ";
		cin >> inputVal;
		list.insertAtTail(inputVal);
	}
	cout << "List after insertion: " << endl;
	list.printList();//PRINTING LIST
	cout << endl;

	//USING COPY COUNSTRUCTOR
	DList<int> listCC = list;
	cout << "Copied Linked List: " << endl;
	listCC.printList();//PRINTING LIST
	cout << endl;

	//SET HEAD
	cout << "Enter value you ant to set at head: ";
	cin >> inputVal;
	list.setHead(list.nodeSearch(inputVal));
	list.printList();

	//SET TAIL
	cout << "Enter value you ant to set at tail: ";
	cin >> inputVal;
	list.setTail(list.nodeSearch(inputVal));
	list.printList();

	//GET HEAD
	cout << "Address of head: " << list.getHead()<<endl;

	//GET TAIL
	cout << "Address of tail: " << list.getTail() << endl;

	//DELETE AT HEAD
	if (list.deleteAtHead())
	{
		cout << "Head is deleted successfully." << endl;
	}
	else
	{
		cout << "No head exists which can be deleted,Linked List is empty" << endl;
	}
	cout << "List after deletion of head: " << endl;
	list.printList();//PRINTING LIST
	cout << endl;

	//DELETE AT TAIL
	if (list.deleteAtTail())
	{
		cout << "Tail is deleted successfully." << endl;
	}
	else
	{
		cout << "No tail exists which can be deleted,Linked List is empty" << endl;
	}
	cout << "List after deletion of tail: " << endl;
	list.printList();//PRINTING LIST
	cout << endl;

	//GET NODE POINTER
	cout << "Enter node number for getting pointer to it: ";
	cin >> inputVal;
	DNode<int>* nodePointer = list.getNode(inputVal);
	if (nodePointer)
	{
		cout << "Pointer to nth node is: " << nodePointer << endl;
	}
	else
	{
		cout << "List is empty! No node exists." << endl;
	}
	cout << endl;

	//INSERT AFTER
	
	cout << "Enter value of node after which you want to insert a node: ";
	cin >> key;
	if (list.insertAfter(key))
	{
		cout << "Node is inserted successfully." << endl;
	}
	else
	{
		cout << "Entered key doesn't exists! Node can not be inserted." << endl;
	}
	cout << "List after insertAfter: " << endl;
	list.printList();//PRINTING LIST
	cout << endl;

	//DELETE AFTER
	cout << "Enter value of node after which you want to delete a node: ";
	cin >> inputVal;
	if (list.deleteAfter(inputVal))
	{
		cout << "After Node is deleted successfully." << endl;
	}
	else
	{
		cout << "Node could not be deleted!." << endl;
	}
	cout << "List after deleteAfter: " << endl;
	list.printList();//PRINTING LIST
	cout << endl;

	//GET LENGTH OF LINKED LIST
	cout << "Total number of nodes are: " << list.getLength();
	cout << endl; cout << endl;

	//SEARCH LINK OF SPECIFIED NODE
	cout << "Enter value of node for finding its link: ";
	cin >> inputVal;
	DNode<int>* nodePointer2 = list.search(inputVal);
	if (nodePointer2)
	{
		cout << "Link of the node is: " << nodePointer2 << endl;
	}
	else
	{

	}
	cout << endl;

	return 0;
}