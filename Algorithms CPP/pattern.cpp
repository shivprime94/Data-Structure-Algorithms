#include<iostream>
using namespace std;


int main() {
    int n;
    cout<<"enter a no: ";
    cin>>n;
    int n1=(n+1)/2;
    int i=1;
    while(i<=n1){
        int k=1;
        while(k<=n1-i){
            cout<<" ";
            k++;
        }
        int j=1;
        while(j<=2*i-1){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
    
    int n2 = n/2;
    i = n2;
    while(i>=1){
        int k=1;
        while(k<=n1-i){
            cout<<" ";
            k++;
        }
        int j=1;
        while(j<=2*i-1){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i--;
    }
    
}
