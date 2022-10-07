#include <iostream>
using namespace std;

class queue_ll
{
private:
  struct node
  {
    int data;
    int N;
    node *next = NULL;
  };
  node *front;
  node *rear;

public:
  queue_ll()
  {
    front = NULL;
    rear = NULL;
  }
  void enqueue(int num, int N);
  void dequeue();
  void display();
  // bool isempty();
  // int peek();
};
int main()
{
  queue_ll q;
  // int ele;
  // cout << "Enter the element: ";
  // cin >> ele;
  q.enqueue(1, 4);
  q.enqueue(2, 1);
  q.enqueue(3, 3);
  q.enqueue(4, 2);
  q.display();
  q.dequeue();
  q.display();
  // cout<<endl<<"Peek element is: "<<q.peek();
}
void queue_ll::enqueue(int ele, int priority)
{
  node *nn = new node;
  node *t = new node;
  // temp = new node();
  nn->data = ele;
  nn->N = priority;
  nn->next = NULL;

  if (front == NULL)
  {
    front = nn;
    rear = nn;
  }
  // else if ((front->N) <= priority)
  else if ((front->N) > priority)
  {
    nn->next = front;
    // front->next = nn;
    // rear =nn;
    front = nn;
  }
  else
  {

    t = front;
    while (((t->next) != NULL) && (((t->next)->N) <= priority))
   
      t = t->next;
    nn->next = t->next;
    t->next = nn;
    nn = rear;
    //  while (((t->next)->N) > priority)
    // nn->next = rear;
    // nn = front;
  }
}

void queue_ll::dequeue()
{
  if (front != NULL) //if list is not empty
  {
    cout << "\nDeleted Node is: " << front->data << " with " << front->N << " priority\n";
    front = front->next;
  }
  else //if list is empty then display error message
    cout << "\nError! List is Empty.";
}

void queue_ll ::display()
{

  node *temp;
  temp = front;
  cout << "Priority Queue: \n";
  cout << "Data \t Priority\n";
  while (temp != NULL)
  {
    cout << temp->data << "\t\t" << temp->N << endl;
    temp = temp->next;
  }
}
// bool queue_ll::isempty()
// {
//     if (front == NULL)
//         return true;
//     else
//     {
//         return false;
//     }
// }
// int queue_ll::peek(){
//     return front->data;
// }