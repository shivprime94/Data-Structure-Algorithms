/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *a = A, *b, *c, *d;
    for(int i = 1; i < B - 1; i++)
        a = a->next;
    b = A;
    for(int i = 1; i < C; i++)
        b = b->next;
    if(B == 1)
    {
        c = A;
        A = b;
    }
    else
    {
        c = a->next;
        a->next = b;
    }
    d = c;
    ListNode *n = c->next;
    while(c != b)
    {
        ListNode *t = n->next;
        n->next = c;
        c = n;
        n = t;
    }
    d->next = n;
    return A;
}
