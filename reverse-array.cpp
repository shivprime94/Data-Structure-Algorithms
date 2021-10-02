#include<iostream>
using namespace std;
void reverse(int input[], int n){
    int temp=input[0];
        input[0]=input[n-1];
        input[n-1]=temp;
}
void printArray(int input[],int n){
    for(int i=1;i<n;i++){
        return input[i];
    }
}
int main(){
    //int n;
    //cin>>n;
    int b[10] = {1,5,4};
    reverse(b,3);
    printArray(b,3);
}
