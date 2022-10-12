#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	   int n;
	   cin>>n;
	   int arr[n];
	   map<int,int>mp;
	   for(int i=0;i<n;i++){
	       cin>>arr[i];
	       mp[arr[i]]++;
	   }
	   int mx=0;
	   for(int i=0;i<n;i++){
	       mx=max(mx,mp[arr[i]]);
	   }
	   cout<<n-mx<<endl;
	}
	return 0;
}
