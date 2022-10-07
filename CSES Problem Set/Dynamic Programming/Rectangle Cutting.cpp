#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<lli,int> pii;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    lli a,b;
    cin>>a>>b;
    vector<vector<lli>>dp(a+1,vector<lli>(b+1,inf));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){dp[i][j]=0;continue;}
            for(int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][j-k]+dp[i][k]+1);
            }
            for(int l=1;l<i;l++){
                dp[i][j]=min(dp[i][j],dp[i-l][j]+dp[l][j]+1);
            }
        }
    }
    cout<<dp[a][b];
    return 0;
}