
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* merge(Node* a,Node* b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    
    Node* res;
    if(a->data < b->data){
        res=a;
        res->bottom=merge(a->bottom,b);
    }
    else{
        res=b;
        res->bottom=merge(a,b->bottom);
    }
    //res->next=NULL;
    return res;
    
}    
    
    
    
    
Node *flatten(Node *head)
{
  if(head==NULL || head->next==NULL){
      return head;
  }
  
  return merge(head,flatten(head->next));
}