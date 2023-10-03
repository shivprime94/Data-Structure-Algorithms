Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
 Input 1 : head = [1,2,3,4,5]
Output 1 : [3,4,5]
Explanation: The middle node of the list is node 3.
  
Input 2 : head = [1,2,3,4,5,6]
Output 2 : [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
  
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
             ListNode * t = head;
             ListNode * r= head->next;
             while(r!=NULL && r->next!=NULL)
             {
                 t=t->next;
                 r=r->next;
                 r=r->next;
             }
        
        if(r==NULL)
            return t;
        return t->next;
        
    }
};
