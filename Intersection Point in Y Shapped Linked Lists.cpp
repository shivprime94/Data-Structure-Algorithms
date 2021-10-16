//soumya@agr427

#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


//Function to find intersection point in Y shaped Linked Lists.
int length_of_list(Node* head)
{
    Node* temp=head;
    int count =0;
    while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        
    return count;
}

int intersectPoint(Node* head1, Node* head2)
{
    // to get the length
    int len1=length_of_list(head1);
    int len2=length_of_list(head2);
    
    //for iteration purpose
    Node* ptr1;
    Node* ptr2;
    
    int diff;
    
    if(len1>len2)
    {
        diff=len1-len2;
        ptr1=head1;
        ptr2=head2;
    }
    else
    {
        
        diff=len2-len1;
        ptr1=head2;
        ptr2=head1;
    }
    
    // we iterate the pointer till the both list are equally away from intersection
    while(diff--)
    {
        ptr1=ptr1->next;
        if(ptr1==NULL)
            return -1;
    }
    
    while(ptr1!=NULL && ptr2!=NULL)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        
        if(ptr1==ptr2)
            return ptr1->data;
    }
    
    return -1;
    
}
