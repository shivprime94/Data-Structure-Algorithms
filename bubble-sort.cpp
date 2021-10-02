#include<iostream>
using namespace std;
void printArray(int input[],int n){
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
}
void bubbleSort(int input[],int n){
    int i=n-1;
    /*for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++)}*/
     int j=n-1;
    while(j>0){
        for(int i=0;i<n-1;i++){
            if(input[i]>input[i+1]){
                swap(input[i],input[i+1]);
            }
           
            
        }j--;
    
    }
}
int main(){
    int n;
    cin>>n;
    int input[100];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
   bubbleSort(input,n);
   printArray(input,n);
return 0;
}
