#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define inf 10000000
 
int c[101],dp[1000100];
int n,x;
 
int rec(int v){
    if(v<0)return inf;
    if(v==0)return 0;
    if(dp[v]!=-1)return dp[v];
    int vall=inf;
    for(int i=0;i<n;i++)
        vall=min(rec(v-c[i])+1,vall);
    return dp[v]=vall;
}
 
void solve(){
    cin>>n>>x;
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<=x;i++)dp[i]=-1;
    int ans=rec(x);
    if(ans>1000000)ans=-1;
    cout<<ans<<endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //int _t;cin>>_t;while(_t--)
        solve();
}
