/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *a = A, *b = A;
    do
    {
        a = a->next;
        if(b->next)
            b = b->next->next;
        else
            return NULL;
    } while(a && b && a != b);
    if(a == b)
    {
        b = A;
        while(a != b)
        {
            a = a->next;
            b = b->next;
        }
        return a;
    }
    return NULL;
}
