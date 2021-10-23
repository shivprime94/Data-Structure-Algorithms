#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define MOD (int)(1e9+7)
 
int dp[1010][1010];
char gd[1010][1010];
int n;
 
int rec(int x,int y){
    if(x>n||y>n)return 0;
    if(gd[x][y]=='*')return 0;
    if(x==n&&y==n)return 1;
    if(dp[x][y]!=-1)return dp[x][y];
    return dp[x][y]=(rec(x+1,y)+rec(x,y+1))%MOD;
}
 
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>gd[i][j];
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,1)<<endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //int _t;cin>>_t;while(_t--)
        solve();
}
