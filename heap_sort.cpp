


#include<iostream>
using namespace std;
void swapp(int *a,int *b){
int temp= *b;
*b=*a;
*a=temp;
}






void max_heapify(int a[],int n,int i){
int largest=i;
int l=2*i;
int r=2*i+1;
while(l<=n&&a[l]>a[largest]){

    largest=l;
}
while(r<=n&&a[r]>a[largest])
{
    largest=r;

}
if(largest!=i){
    swapp(&a[largest],&a[i]);
    max_heapify(a,n,largest);
}
}
void heap_sort(int a[],int n){
for(int i=n/2;i>=1;i--){
    max_heapify(a,n,i);
    //heapify
}

for(int i=n;i>=1;i--){
    swapp(&a[1],&a[i]);
    max_heapify(a,i-1,1);

}
//deletion

}
void print(int arr[],int n){
for(int i=0;i<n;i++){
    cout<<arr[i];
}}
int main(){
    int arr1[6]={1,7,9,10,8,5};
    int i;
    cout<<"the original array is";
    print(arr1,6); cout<<endl;
heap_sort(arr1,6);

    print(arr1,6);}

