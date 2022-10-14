#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class stack
{
    node *head;

public:
    stack()
    {
        head = NULL;
    }
    void push(int d)
    {

        if (head == NULL)
        {
            head = new node(d);
        }
        else
        {
            node *n = new node(d);
            n->next = head;
            head = n;
        }
    }
    void pop()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            node *t = head;
            head = head->next;
            delete t;
        }

        return;
    }
    bool empty()
    {
        return head == NULL;
    }
    int top()
    {
        return head->data;
    }
};
int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (s.empty() != true)
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}