//You are given the head of a linked list, reverse the list and return the reversed list

/*
  Example :
   Input : head = [1,2,3,4,5]
   Output : [5,4,3,2,1]
*/

/*
  Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
*/


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev,*cur,*next;
    prev=NULL;
    cur=head;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}
