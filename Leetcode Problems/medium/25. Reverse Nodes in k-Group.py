# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        prev=None
        temp=head
        for i in range(k):
            if temp==None:
                return head
            temp=temp.next
        temp=head
        for i in range(k):
            curr=temp
            temp=temp.next
            curr.next=prev
            prev=curr
        head.next=self.reverseKGroup(temp,k)
        return prev
        