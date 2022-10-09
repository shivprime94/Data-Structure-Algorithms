//You are given a linked list, you have to swap every two adjacent nodes and return its head

/*
  Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
*/


struct ListNode* swapPairs(struct ListNode* head){
    if(!head||!head->next)
        return head;
    struct ListNode* temp=head->next;
    head->next=swapPairs(head->next->next);
    temp->next=head;
    return temp;
}
