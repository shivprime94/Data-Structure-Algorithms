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
        next=NULL;
        prev=NULL;
    }
    Node()
    {
        next=NULL;
        prev=NULL;
    }
};
void Search(Node* &head, int num){
    if (head==NULL){
        cout << "List is empty";
    }
    else{
        Node*temp =head;
        while(temp->next!=head && temp->data!=num){
            temp=temp->next;
        }
        if (temp->data==num){
            cout << "Element found";
        }
        else cout << "Element not found";
    }
}
void display(Node* & head){
    if (head==NULL){
        cout << "List is empty";
    }
    else{
        Node* temp=head;
        while(temp->next!=head){
            cout << temp->data << endl;
            temp=temp->next;
        }
        cout << temp->data << endl;

    }
}
void InsertBeg(Node* &head, int num){
    Node* temp= new Node(num);
    if(head==NULL){
        head=temp;
        head->next=head;
    }
    else {
        temp->next=head;
        Node* temp1=head;
        while(temp1->next!=head){
            temp1=temp1->next;
        }
        temp1->next=temp;
    head=temp;
    }
}
void InsertEnd(Node* &head, int num){
    Node* temp= new Node(num);
    if (head==NULL){
        head=temp;
        head->next=head;
    }
    else {
        Node*temp1=head;
        while(temp1->next!=head){
        temp1=temp1->next;
        }
        temp1->next=temp;
        temp->next=head;
    }
}
void InsertSpec(Node* &head, int num, int value){
    Node* temp= new Node(num);
    if (head==NULL){
        head=temp;
        head=head->next;
    }
    else {
        Node* temp1=head;
        while(temp1->next!=head && temp1->data!=value){
            temp1=temp1->next;
        }
        if (temp1->next==head && temp1->data!=value){
            cout << "Node is not present";
        }
        else {
            temp->next=temp1->next;
            temp1->next=temp;
        }
}
}
void DeleteBeg(Node* &head){
    if (head==NULL){
        cout << "The list is empty";
    }
    else {
        Node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=head->next;
        head=head->next;
        free(temp);
    }
}
void DeleteEnd(Node* &head){
    if (head==NULL){
        cout << "The list is empty";
    }
    else{
        Node*temp=head;
        Node*prev=temp;
        while(temp->next->next!=head){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp;
        temp->next=head;
        free(temp);
    }
}
void DeleteSpec(Node* &head, int value){
    if (head==NULL) cout << "List is empty";
    else {
        Node* temp=head;
        Node* prev=temp;
        while(temp->next!=head && temp->data!=value){
            prev=temp;
            temp=temp->next;
        }
        if (temp->data!=value){
            cout << "Value is not present";
        }
        else if (temp==head){
            DeleteBeg(head);
        }
        else if (temp->next==head){
            DeleteEnd(head);
        }
        else {
            prev->next=temp->next;
        }
    }
}
int main(){
    Node *n1=new Node(10);
    Node *n2=new Node(20);
    Node *n3= new Node(30);
    Node* head=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=head;
    DeleteSpec(head,30);
    display(head);
}