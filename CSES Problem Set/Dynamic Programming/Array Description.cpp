#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define mod 1000000007
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<int,int> pii;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
lli power(lli x, lli y, long long int m = mod) { lli ans = 1; x %= m; while (y) {if (y & 1)ans = (x * ans) % m; x = (x * x) % m; y >>= 1;} return ans;}
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vi arr(n);
    for(int &a:arr)cin>>a;
    vector<vector<lli>>dp(n,vector<lli>(m+2,0));
    for(int i=1;i<=m;i++){
       if(arr[0]==0) dp[0][i]=1;
       else dp[0][arr[0]]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=m;j>0;j--){
           if(arr[i]==0)dp[i][j]=(dp[i-1][j-1]%mod+dp[i-1][j+1]%mod+dp[i-1][j]%mod)%mod;
                else{ dp[i][arr[i]]=(dp[i-1][arr[i]-1]%mod+dp[i-1][arr[i]+1]%mod+dp[i-1][arr[i]]%mod)%mod;break;}
        }
    }
    lli ans=0;
    for(int i=1;i<=m;i++) {ans+=dp[n-1][i];ans%=mod;}
    cout<<ans;
    return 0;
}