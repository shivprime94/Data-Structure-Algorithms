/*
  Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
*/


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int i=0;
    struct ListNode *temp=head;
    if(head->next==NULL)
        return NULL;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    if(i==n)
        return head->next;
    i=i-n-1;
    temp=head;
    while(i>0)
    {
        i--;
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
}
