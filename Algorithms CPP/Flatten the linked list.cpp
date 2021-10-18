//@soumyaagr427

#include <bits/stdc++.h>

struct Node
{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) 
{

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

/*  Function which returns the  root of 
    the flattened linked list. */

Node* merge(Node* head1,Node *head2)
{
    //base condition for recursion 
    if(head1==0)return head2;
    if(head2==0)return head1;
    
    Node* res;
    
    //recursively call the smaller node and links them
    if(head1->data<=head2->data)
    {
        res=head1;
        res->bottom=merge(head1->bottom,head2);
    }
    else
    {
        res=head2;
        res->bottom=merge(head1,head2->bottom);
    }
    
    res->next=NULL;
    
    return res;
}

Node *flatten(Node *root)
{
   //traverse the horizontal list to add two sublist and return their head
   if(root==0 || root->next==0)
        return root;
    
    return merge(root,flatten(root->next));
   
}
