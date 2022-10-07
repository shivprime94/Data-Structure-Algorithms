#include <iostream>
using namespace std;
// #define n 100
class queues
{

    int q[100];
    int f = -1;
    int r = -1;
    int n;

public:
    void enqueue(int ele);
    int dequeue();
    void display();
    bool isfull();
    bool isempty();
    int peek();
};
int main()
{

    queues q;
    int n;
    cout << "Enter the number of elements to be inserted: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        q.enqueue(n);
    }
    q.display();

    int del;
    cout << "Enter the number of elements to be deleted: ";
    cin >> del;
     for (int i = 0; i < del; i++)
    {
            q.dequeue();
    }
    q.display();
    // cout<<"The element at peek is: "<<q.peek();
}
void queues::enqueue(int size)
{
    int ele;
    cout << "Enter the element of the queue: ";
    cin >> ele;

    if (isfull())
    {
        cout << "Overflow" << endl;
        return;
    }
    else
    {
        if (isempty())
        {
            f = 0;
        }
        r++;
        q[r] = ele;
    }
}
int queues::dequeue()
{
    int temp;
    if (isempty())
    {
        cout << "Underflow" << endl;
    }
    else
    {
        temp = q[f];
        if (f >= r)
        {
            f = r = -1;
        }
        else
        {
            f++;
        }
    }
    cout << "Deleted element is: " << temp<<endl;
}
void queues::display()
{
    if (isempty())
    {
        cout << "underflow";
    }
    else
    {
        cout<<"The queue is: ";
        for (int i = f; i <= r; i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;
    }
}
bool queues ::isempty()
{
    if (f == -1 && r == -1)
    {
        return true;
    }
    else
        return false;
}
bool queues::isfull()
{
    if (r == n - 1)
    {
        return true;
    }
    else
        return false;
}
int queues::peek()
{
    return q[f];
}
