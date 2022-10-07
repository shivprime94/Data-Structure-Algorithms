#include<iostream>
#include<cmath>
using namespace std;

int jumpSearch( int arr[], int L, int key)
{
int step = sqrt(L);
int left = 0;
int right = step;

while(arr[right]<= key && right <= L)
{
    left = right;
    right = right + step;

    if( right > L-1)
{
    right = L-1;
}
}


for( int i = left; i <= right; i++)
{
   if(arr[i] == key)
   {
       return i;
   }
}
return -1;
}

int main()
{
    int arr[] = {5,10,15,20,25,30,35,40,45,50,55,60,65,70};
    int L = sizeof(arr)/ sizeof(arr[0]);

    cout<<"Enter the number to be searched"<<endl;
    
    int key;
    cin>> key;

    int result = jumpSearch( arr , L, key);

    cout<< result;
    return 0;
}
