#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define MOD (int)(1e9+7)
 
int c[101],dp[1000100];
int n,x;
 
int rec(int v){
    if(v<0)return 0;
    if(v==0)return 1;
    if(dp[v]!=-1)return dp[v];
    int vall=0;
    for(int i=0;i<n;i++)
        (vall+=rec(v-c[i]))%=MOD;
    return dp[v]=vall%MOD;
}
 
void solve(){
    cin>>n>>x;
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<=x;i++)dp[i]=-1;
    int ans=rec(x);
    cout<<ans%MOD<<endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //int _t;cin>>_t;while(_t--)
        solve();
}
