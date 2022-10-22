#include<bits/stdc++.h>
using namespace std;
int check(int arr[],int n){
    sort(arr, arr+n);
    for(int i=0;i<n-1;i++){
        if((arr[i+1] - arr[i]) <= 0)
         return 0;

    }
    return 1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(check(arr,n))
        cout<<"yes"<<endl;
        else
        cout<<"no"<<endl;
    }
    return 0;
}
