/*

https://leetcode.com/problems/rotate-list/description/
Algorithm:
1. count the length of LL
2. Make the list circular by pointing last node to the head
3. Point (len-k)th node to NULL

*/
    //compute length
    ListNode *temp = head;
    int len = 1;
    while(temp->next){
        len++;
        temp = temp -> next;
    }
    
    //go till kth node
    temp -> next = head;
    k = k % len;
    k = len - k;
    while(k--) temp = temp -> next;
    
    //make node head & break connection
    head = temp -> next;
    temp -> next = NULL;
    return head;
}


//Time Complexity: O(n)
//Space Complexity: O(1)
