#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next = NULL;

    Node(int data) {
        this->data = data;
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

int getValueByPosition(Node* head, int pos) {
    if(pos<1) {        
        cout<<"Position not found!";
        return -1;
    }

    int count = 1;
    while(head->next != NULL) {
        if(count == pos) {
            return head->data;
        } else {
            head = head->next;
            count++;
        }
    }

    cout<<"Position not found!";
    return -1;
}

// Time Complexity - O(n)
// Space Complexity - O(1)
bool isCircular(Node* head) {
    if(head==NULL) {
        return true;
    }

    Node* temp = head;

    while(temp != NULL) {
        temp = temp->next;

        if(temp == head) {
            return true;
        }
    }

    return false;
}

// Time Complexity - O(n)
// Space Complexity - O(n)
bool detectLoop(Node* head) {
    if(head==NULL) {
        return false;
    }

    map <Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL) {
        if(visited[temp] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

int main() {
    //Node* node1 = new Node(0);

    Node* head = NULL;
    Node* tail = NULL;

    for(int i=1; i<=5; i++) {
        insertAtTail(head, tail, pow(2,i));
    }
    print(head);

    tail->next = head->next->next;

    if(detectLoop(head)) {
        cout<<"Given linked list contains a loop in it";
    } else {
        cout<<"Given linked list doesn't contain a loop in it";
    }
    
    return 0;
}