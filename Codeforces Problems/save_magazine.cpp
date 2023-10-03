#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mod 1000000007
#define pb push_back
#define MULTICASE
 
 
 
 
void solve(){
    int n;cin>>n;
    vector<int> v(n);
    string a;cin>>a;
   // for(auto &it :v) cin>>it;
   for(int i=0;i<n;i++) cin>>v[i];
     int ans=0,in,mi;
    for(int i=0;i<n;i++){
      if(a[i]=='0'){
        in=i+1;
        mi=i;
        while(in<n&&a[in]=='1'){
            if(v[in]<v[mi]){
                mi=in;
            }
            in++;
        }
        swap(a[i],a[mi]);
        i=in-1;
 
      }
 
      }
      for(int i=0;i<n;i++){
        if(a[i]=='1') ans+=v[i];
      }
      cout<<ans<<endl;
    
}
 
 
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
#ifdef MULTICASE
    int t;
    cin>>t;
    while(t--)
#endif
    solve();
    return 0;
}
