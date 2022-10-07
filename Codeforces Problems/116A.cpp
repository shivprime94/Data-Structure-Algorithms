#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"


int32_t main(){
    int t,mx=INT_MIN;
    cin>>t;
    int r = 0;
    while(t--){
       int a ,b;
       cin>>a>>b;
        r = r-a+b;
        mx = max(mx,r);
   
    }
       cout<<mx<<endl;
    return 0;
}