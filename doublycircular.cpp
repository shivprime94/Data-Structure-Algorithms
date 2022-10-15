#include <iostream>
using namespace std;

class Node{
    public: 
    Node* head;
    Node* prev;
    Node* next;
    int data;
    Node(int d){
        data=d;
        prev=NULL;
        next=NULL;
    }
    Node(){
        prev=NULL;
        next=NULL;
    }
};
void display(Node* &head){
    Node* temp=head;
    while(temp->next!=head){
        cout << temp->data << endl;
        temp=temp->next;
    }
    cout << temp->data << endl;
}
void InsertBeg(Node* &head, int x){
    Node* temp=new Node(x);
    if (head==NULL){
        temp->prev=temp->next=temp;
        head=temp;
    }
    else{
        temp->next=head;
        temp->prev=head->prev;
        head->prev=temp;
        temp->prev->next=temp;
        head=temp;
    }
}
void InsertEnd(Node* &head, int x){
    Node* temp = new Node(x);
    if (head==NULL){
        temp->next=temp->prev=temp;
        head=temp;
    }
    else{
        temp->next=head;
        temp->prev=head->prev;
        head->prev->next=temp;
        head->prev=temp;
    }
}
void InsertSpec(Node* &head, int x, int value){
    Node* temp= new Node(x);
    if (head==NULL){
        temp->prev=temp->next=temp;
        head=temp;
    }
    else {
        Node* temp1=head;
        while(temp1->next!=head && temp1->data!=value){
            temp1=temp1->next;
        }
        temp->next=temp1->next;
        temp->prev=temp1;
        temp1->next=temp;
        temp1->next->prev=temp;
    }
}
void DeleteBeg(Node* &head){
    if (head==NULL){
        cout << "List is empty";
    }
    else{
        Node* temp=head;
        if (temp->next==head){
            head=NULL;
        }
        else{
        head->prev->next=head->next;
        head->next->prev=head->prev;
        head=head->next;
        free(temp);
    }
}
}
void DeleteEnd(Node* &head){
    if (head==NULL){
        cout << "List is empty";
    }
    else{
        Node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        if (temp==head){
            head=NULL;
        }
        else {
            temp->prev->next=head;
            head->prev=temp->prev;
            delete temp;
        }
    }
    
}
void DeleteSpec(Node* &head, int value){
    if (head==NULL){
        cout << "List is empty";
    }
    else {
        Node* temp =head;
        while(temp->next!=head && temp->data!=value){
            temp=temp->next;
        }
        if (temp->data!=value){
        cout << "Element not found";
        }
        else if (temp==head){
            DeleteBeg(head);
        }
        else if (temp->next==head){
            DeleteEnd(head);
        }
        else {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
    }
}
int main(){
    Node *n1=new Node(4);
    Node *n2=new Node(12);
    Node *n3=new Node(10);
    Node* head=n1;
    n1->next=n2;
    n1->prev=n3;
    n2->next=n3;
    n2->prev=n1;
    n3->next=n1;
    n3->prev=n2;
    DeleteSpec(head,4);
    display(head);
}