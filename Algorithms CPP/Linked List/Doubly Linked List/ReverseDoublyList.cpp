#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next = NULL;
    Node* prev = NULL;

    Node(int data) {
        this->data = data;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data) {
    // FOr empty list
    if(head == NULL) {
        Node* insertNode = new Node(data);
        head = insertNode;
        tail = insertNode;
        return;
    }

    Node* insertNode = new Node(data);
    insertNode->next = head;
    head->prev = insertNode;
    head = insertNode;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    // For empty list
    if(tail == NULL) {
        Node* insertNode = new Node(data);
        head = insertNode;
        tail = insertNode;
        return;
    }

    Node* insertNode = new Node(data);
    tail->next = insertNode;
    insertNode->prev = tail;
    tail = insertNode;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    if(position==1) {
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1) {
        temp = temp->next;
        count++;
    }
    
    if(temp->next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }
    
    Node* insertNode = new Node(data);
    insertNode->next = temp->next;
    insertNode->prev = temp;
    temp->next = insertNode;
    
    temp = insertNode->next;
    temp->prev = insertNode;
}

void printByHead(Node* &head) {
    if(head == NULL) {
        cout<<"List is empty\n";
        return;
    }

    Node* temp = head;

    cout<<"Print By Head : ";
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

void printByTail(Node* &tail) {
    if(tail == NULL) {
        cout<<"List is empty\n";
        return;
    }
    
    Node* temp = tail;

    cout<<"Print By Tail : ";
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }

    cout<<endl;
}

void deleteNodeByPosition(Node* &head, Node* &tail, int position) {
    if(position == 1) {
        Node* current = head;
        head = current->next;
        head->prev = NULL;
        delete current;
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1) {
        if(temp->next == NULL) {
            cout<<"Position Not Found!"<<endl;
            return;
        }

        temp = temp->next;
        count++;
    }

    Node* current = temp->next;
    temp->next = current->next;
    
    if(current->next == NULL) {
        tail = temp;
    } else {
        current->next->prev = temp;
    }

    delete current;
}

void deleteNodeByValue(Node* &head, Node* &tail, int value) {
    if(head->data == value) {
        head = head->next;
        head->prev = NULL;
        return;
    }

    Node* current = head;
    Node* temp = current;

    while(current->data != value) {
        if(current->next == NULL) {
            cout<<"Element Not Found!"<<endl;
            return;
        }

        temp = current;
        current = current->next;
    }
    
    if(current->next == NULL) {
        tail = temp;
    } else {
        current->next->prev = temp;
    }

    temp->next = current->next;
    delete current;
}

int lengthOfList(Node* &head) {
    int length = 1;
    Node* temp = head;

    while(temp->next != NULL) {
        length++;
        temp = temp->next;
    }

    return length;
}

void reverseDLL(Node* &head, Node* &tail) {
    if(head->next == NULL) {
        return;
    }

    if(head == NULL) {
        cout<<"List is empty!";
        return;
    }
    
    tail = head;

    while(head->next != NULL) {
        Node* temp = head;
        head = head->next;

        temp->next = temp->prev;
        temp->prev = head;
    }

    head->next = head->prev;
    head->prev = NULL;
}

int main() {
    //Node* node1 = new Node(10);

    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtPosition(head, tail, 4, 99);

    printByHead(head);
    printByTail(tail);
    cout<<"Head = "<<head->data<<" & Tail = "<<tail->data<<endl;

    reverseDLL(head, tail);
    printByHead(head);
    printByTail(tail);
    cout<<"Head = "<<head->data<<" & Tail = "<<tail->data<<endl;

    return 0;
}