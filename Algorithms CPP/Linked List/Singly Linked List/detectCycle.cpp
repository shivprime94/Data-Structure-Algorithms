// Detect Cycle or Loop in Linked List
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again
// by continuously following the next pointer. Internally, pos is used to denote the index of the
// node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
#include <bits/stdc++.h>
using namespace std;

// Creating a class node, with user-defined data types within it
class node
{
public:
    int data;
    node *next;

    node() {}

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// Adding of node, with user defined data at the head of the Linked List
void insertAtHead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

// Adding of node, with user defined data at the end of the Linked List
void insertAtLast(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *n = new node(data);
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
}

// Detect cyccle in a Linked List
// Brute Force Approach
// Time Complexity : O(N)
// Space Complexity : O(N) [due to unordered_set]
bool detectCycleBrute(node *h1)
{
    unordered_set<node *> st;
    while (h1 != NULL and st.find(h1) == st.end())
    {
        st.insert(h1);
        h1 = h1->next;
    }

    // if particular node present in set, then return true else false
    if (st.find(h1) != st.end())
        return true;
    return false;
}

// Detect cyccle in a Linked List
// Brute Force Approach
// Time Complexity : O(N)
// Space Complexity : O(1) [As no unordered_set used]
bool detectCycleOpt(node *head)
{
    if (head == NULL or head->next == NULL)
        return false;

    // Using slow and fast pointers i.e. Two pointer approach
    node *slow = head;
    node *fast = head;
    while (fast->next != NULL and fast->next->next != NULL)
    {
        // slow moving one step a time, while fast moving two steps a time
        slow = slow->next;
        fast = fast->next->next;

        // if at any instance they are same, then cycle detected, else no cycle detected
        if (slow == fast)
            return true;
    }

    return false;
}

// Printing the Linked List with head reference
void printLL(node *head)
{
    while (head != NULL)
    {
        if (head->next == NULL)
            cout << head->data << endl;
        else
            cout << head->data << "-->";
        head = head->next;
    }
}

// Executing main
int main()
{
    node *head1 = NULL;
    insertAtHead(head1, 3);
    insertAtLast(head1, 2);
    insertAtLast(head1, 0);
    insertAtLast(head1, -4);

    // Printing Original Linked List
    cout << "Original Linked List : " << endl;
    printLL(head1);

    // Creating a loop in Linked List
    head1->next->next->next->next = head1->next;

    // Checking if Cycle present in Linked List or not
    if (detectCycleOpt(head1))
        cout << "Cycle Detected in Linked List!!" << endl;
    else
        cout << "No Cycle Detected in Linked List!!!" << endl;
    return 0;
}