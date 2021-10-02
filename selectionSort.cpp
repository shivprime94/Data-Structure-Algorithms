//C++ program for selection sort
//Time Complexity: O(n2)
//Space Complexity: O(1) 

#include <bits/stdc++.h>
using namespace std;
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void SelectionSort(int arr[], int n)
{
    int i, j, min_indx;

    for (i=0; i < n-1; i++)
    {
        min_indx = i;
        for (j=i+1; j < n; j++)
        if (arr[j] < arr[min_indx])
            min_indx = j;
        swap(&arr[min_indx], &arr[i]);
    }
}
 
void PrintArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout<<arr[i]<< " ";
    cout<<endl;
}
 
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: \n";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    SelectionSort(arr, n);
    cout<<"Sorted array: \n";
    PrintArray(arr, n);
    return 0;
}