#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define MOD (int)(1e9+7)
 
int c[110],dp[1000010];
int n,x;
 
void solve(){
    cin>>n>>x;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        cin>>c[i];
    dp[0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j+c[i]<=x;j++)
            if(dp[j]>0)
                (dp[j+c[i]]+=dp[j])%=MOD;
    cout<<dp[x]%MOD<<endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //int _t;cin>>_t;while(_t--)
        solve();
}
