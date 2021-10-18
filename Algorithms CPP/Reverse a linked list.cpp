//@soumyaagr@427

#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
  
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // three pointers to store links and swapping
         Node* prev=NULL; 
         Node* curr=head;
         Node* nextptr;
         
         while(curr!=NULL)
         {
             nextptr=curr->next;
             curr->next=prev;
             
             prev=curr;
             curr=nextptr;
         }
        
        return prev; // as it becomes the new head
    }
    
};
    

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}
