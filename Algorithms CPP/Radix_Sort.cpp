#include<iostream>
#include<string>
#include<cmath>
using namespace std;

// Linked List node
class Node{
public:
    int value;
    Node* next;
};

void Insert(Node** ptrBins, int value, int idx){
    Node* temp = new Node;
    temp->value = value;
    temp->next = nullptr;
 
    if (ptrBins[idx] == nullptr){
        ptrBins[idx] = temp;  // ptrBins[idx] is head ptr
    } else {
        Node* p = ptrBins[idx];
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}
 
int Delete(Node** ptrBins, int idx){
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

//uiliiets
int Max(int A[], int n){
    int max = -32768;
    for (int i=0; i<n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int countDigits(int x){
    int count = 0;
    while (x != 0){
        x = x / 10;
        count++;
    }
    return count;
}

int getBinIndex(int x, int idx){
    return (int)(x / pow(10, idx)) % 10;
}
//RADIX SORT
void radix_sort(int A[], int n)
{
    int max = Max(A, n);
    int nPass = countDigits(max);
    Node** bins = new Node*[10]{NULL};

    for (int pass = 0; pass < nPass; pass++)
    {
        for (int i = 0; i < n; i++)
        {
            int index = getBinIndex(A[i],pass);
            Insert(bins,A[i],index);
        }
        
        int i=0,j=0;
        while (i<10)
        {
            while (bins[i]!=NULL)
            {
                A[j++]=Delete(bins,i);       
            }
            i++;
        }
        for (int i = 0; i < 10; i++)
        {
            bins[i]=NULL;
        }
    }
    delete [] bins;
}

int main(){
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A) / sizeof(A[0]);
    radix_sort(A,n);
    for (size_t i = 0; i < n; i++)
    {
        cout << "--" << A[i] << "--" << flush;
    }


return 0;
}