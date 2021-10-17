
#include<iostream>
using namespace std;
void swapp(int *a,int *b){
int temp= *b;
*b=*a;
*a=temp;
}
void Bubble_sort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (arr[j+1]<arr[j]){
               swapp(&arr[j+1],&arr[j]);
            }
        }
    }
}




void selection_sort(int arr[],int n){
    int smallest;
for(int i=0;i<n-1;i++){
 smallest=i;
    for(int j=i+1;j<n;j++){

        if(arr[j]<arr[smallest]){
            smallest=j;
        }

    }swapp(&arr[i],&arr[smallest]);
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
      selection_sort(arr1,6);

    print(arr1,6);}
