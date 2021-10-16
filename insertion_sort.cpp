
#include<iostream>
using namespace std;
void swapp(int *a,int *b){
int temp= *b;
*b=*a;
*a=temp;
}


void insertion_sort(int arr[],int n){

for(int i=1;i<n;i++){
    int temp=arr[i];
    int j;
   for( j=i-1;j>=0 &&arr[j]>temp;j--){

    arr[j+1]=arr[j];
   }
   arr[j+1]=temp;
}


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
 insertion_sort(arr1,6);

    print(arr1,6);}
