#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution
{
    Node *reverse(Node *curr)
    {
        Node *prev = NULL;
        Node *next;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr = prev;
        return curr;
    }

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        first = reverse(first);
        second = reverse(second);

        int sum = 0;
        int carry = 0;

        Node *temp;
        Node *res = NULL;
        Node *curr = NULL;

        while (first != NULL || second != NULL)
        {
            sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
            carry = (sum >= 10) ? 1 : 0;
            sum = sum % 10;

            temp = new Node(sum);
            if (res == NULL)
                res = temp;
            else
                curr->next = temp;
            curr = temp;

            if (first)
                first = first->next;
            if (second)
                second = second->next;
        }

        if (carry > 0)
        {
            temp = new Node(carry);
            curr->next = temp;
            curr = temp;
        }

        res = reverse(res);
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}