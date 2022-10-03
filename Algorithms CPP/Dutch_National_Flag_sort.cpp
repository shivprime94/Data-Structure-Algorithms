#include <iostream>
using namespace std;

// Swapping the elements
void Swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// DNF Sort Function
void DNF_Sort(int a[], int n)
{
    int low = 0, mid = 0, high = n - 1;

    // Looping till our mid is less than high
    while (mid <= high)
    {

        if (a[mid] == 0) // If our mid element is zero then we have swap a[mid] and a[low] element.
        {
            Swap(a, mid, low);
            low++;
            mid++;
        }
        else if (a[mid] == 1) // If our mid element is one , we simply have to increase the mid.
        {
            mid++;
        }
        else
        {
            Swap(a, mid, high); // If our mid element is two then we have swap a[mid] and a[high] element.
            high--;
        }
    }
}

int main()
{
    int a[] = {0, 1, 2, 0, 0, 1, 2, 2};
    int n = (sizeof(a)) / (sizeof(a[0]));

    cout << "Before DNF Sorting : \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    DNF_Sort(a, n);

    cout << "\n\nAfter DNF Sorting : \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

/*
Output :-
Before DNF Sorting :
0 1 2 0 0 1 2 2
After DNF Sorting :
0 0 0 1 1 2 2 2
*/
