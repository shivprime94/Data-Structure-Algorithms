// https://www.codechef.com/SNCK1A21/problems/MINLCM1
#include <bits/stdc++.h>
#include<numeric>
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
#define int ll
using namespace std;
int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int x,k;
        cin>>x>>k;
        //if k==1 k==2
        // if((2*(x))<=x*k){
        //     cout<<2*x<<" ";
        // }
        // else{
        //     cout<<(x)*(x+1)<<" ";
        // }
        cout<<2*x<<" ";
        cout<<(x*k)*(x*k-1)<<endl;
        //both will be coprime
        
        /*
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=x;i<x*(k);i++){
            for(int j=i+1;j<=x*k;j++){
                int a=lcm(i,j);
                if(a<mini){mini=a;}
                if(a>maxi){maxi=a;}
            }    
        }
        */
        //cout<<mini<<" "<<maxi<<endl;
    }
}
