//Link - https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    ListNode*reverse(ListNode*nextnode){
        ListNode*curr=nextnode;
        ListNode*prev=NULL;
        while(curr!=NULL){
        ListNode*temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        }
        return prev;
        
        
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        fast=head->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*nextnode=slow->next;
        slow->next=NULL;
        ListNode*sechead=reverse(nextnode);
        while(sechead!=NULL&&head!=NULL){
            if(head->val!=sechead->val){
                return false;
            }
            head=head->next;
            sechead=sechead->next;
        }
        
        
        return true;
        
    }
};
