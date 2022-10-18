#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data) {
    // For empty list
    if(head == NULL) {
        Node* insertNode = new Node(data);
        head = insertNode;
        tail = insertNode;
        return;
    }

    Node* insertNode = new Node(data);
    insertNode->next = head;
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
    
    if(temp == NULL) {
        insertAtTail(head, tail, data);
        return;
    }
    
    Node* insertNode = new Node(data);
    insertNode->next = temp->next;
    temp->next = insertNode;
}

void print(Node* &head) {
    if(head == NULL) {
        cout<<"List is empty\n";
        return;
    }

    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

void deleteNodeByPosition(Node* &head, Node* &tail, int position) {
    if(position == 1) {
        Node* current = head;
        head = current->next;
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
    }
    
    delete current;
}

void deleteNodeByValue(Node* &head, Node* &tail, int value) {
    if(head->data == value) {
        head = head->next;
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

void reverseLL(Node* &head, Node* &tail) {
    if(head == NULL) {
        cout<<"Empty List! Nothing to reverse!"<<endl;
        return;
    }

    tail = head;
    Node* nextNode = head->next;
    head->next = NULL;

    while(nextNode != NULL) {
        Node* temp = nextNode->next;
        nextNode->next = head;
        head = nextNode;
        nextNode = temp;
    }
}

Node* recursiveApproach1(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* restNodes = recursiveApproach1(head->next);

    head->next->next = head;
    head->next = NULL;
    return restNodes;
}

void recursiveApproach2(Node* &head, Node* curr, Node* prev) {
    if(curr == NULL) {
        head = prev;
        return;
    }

    recursiveApproach2(head, curr->next, curr);
    curr->next = prev;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);

    print(head);
    cout<<"Head = "<<head->data<<" & Tail = "<<tail->data<<endl;

    //tail = head;
    //recursiveApproach2(head, head, NULL);
    
    //head = recursiveApproach1(tail = head);

    reverseLL(head, tail);
    print(head);
    cout<<"Head = "<<head->data<<" & Tail = "<<tail->data<<endl;

    return 0;
}