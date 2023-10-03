#include <iostream>
using namespace std;
class Node{
    public:
    Node* next;
    Node* prev;
    int data;
    Node(int d){
        data =d;
        next=NULL;
        prev=NULL;
    }};
void search(Node* &head, int d){
    if (head == NULL){
        cout << "List is empty";
        exit(0);
    }
    Node* temp=head;
    while(temp!=NULL && temp->data!=d){
        temp=temp->next;
    }
    if (temp==NULL){
        cout << "Element not found";
    }
    else cout << "Element found";
}
void display(Node* &head){
    if (head == NULL){
        cout << "List is empty";
    }
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << endl;
        temp=temp->next;
    }
}
void InsertBeg(Node* &head, int d){
    Node* temp = new Node(d);
    temp->prev=NULL;
    temp->next=head;
    if (head==NULL){
        head=temp;
    }
    else {
        head->prev=temp;
        head=temp;
    }
}
void InsertEnd(Node* &head, int d){
    Node*temp = new Node(d);
    temp->prev=NULL;
    temp->next=NULL;
    if (head==NULL){
        temp=head;
    }
    else{
        Node*temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
        temp->prev=temp1;
    }
}
void deleteBeg(Node* &head){
    if (head==NULL) cout << "list is empty";
    else {
        head=head->next;
        head->prev=NULL;
    }
}
void deleteEnd(Node* &head){
    if (head==NULL) cout << "list is empty";
    else {
        Node*temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
    }
}
void deleteSpec(Node* &head,int num)
{
    if(head==NULL)
        cout<<"Empty List"<<endl;
    else
    {
        Node* temp=head;
        while(temp->next!=NULL && temp->data!=num)
        {
            temp=temp->next;
        }
        if(temp==head)
        {
            head=head->next;
            head->prev=NULL;
        }
        else if(temp->next==NULL)
        {
            temp->prev->next=NULL;
        }
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
        }
            
    }
}

int main(){
    Node *n1=new Node(10);
    Node *n2=new Node(20);
    Node *n3= new Node(50);
    Node *n4=new Node(60);
    Node *head =n1;
    n1->next=n2;
    n2->prev=n1;
    n2->next=n3;
    n3->prev=n2;
    n3->next=n4;
    n4->prev=n3;
    deleteEnd(head);
    display(head);
}
