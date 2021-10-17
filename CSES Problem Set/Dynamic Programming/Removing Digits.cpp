#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define inf (int)(1e9+7)
 
int dp[1000010];
int n;
 
bool hasdig(int num,int fac){
    while(num){
        if(num%10==fac)return true;
        num/=10;
    }
    return false;
}
 
void solve(){
    cin>>n;
    dp[0]=0;
    for(int i=1;i<=n;i++)dp[i]=inf;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=9;j++){
            if(hasdig(i+j,j)){
                dp[i+j]=min(dp[i+j],dp[i]+1);
            }
        }
    }
    cout<<dp[n]<<endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //int _t;cin>>_t;while(_t--)
        solve();
}
