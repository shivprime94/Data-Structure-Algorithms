#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define mod 1000000007
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<int,int> pii;
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin>>n;
    lli mx=n*(n+1)/2;
    if(mx%2==1){
        cout<<0;return 0;
    }
    vector<lli>dp(mx+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=mx/2-i;j>=0;j--){
            dp[j+i]=(dp[j+i]+dp[j])%(1000000007);
        }
    }
    cout<<(((dp[mx/2])%mod)*(500000004%mod))%mod;
    return 0;
}