#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<int,int> pii;
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin>>n;
    vi cost(n),dp(1e5+1,0);
    dp[0]=1;
    for(int &u:cost)cin>>u;
    for(int j=0;j<n;j++)
    for(int i=1e5;i-cost[j]>=0;i--)
        dp[i]=dp[i]||dp[i-cost[j]];
    vi s;
    for(int i=1;i<=1e5;i++)
        if(dp[i]) s.pb(i);
    cout<<s.size()<<"\n";
    for(int i=0;i<s.size();i++)cout<<s[i]<<" ";
    return 0;
}