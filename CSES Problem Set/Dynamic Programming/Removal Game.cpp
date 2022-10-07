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
    int n;
    cin>>n;
    vector<lli>dp(n+1,0);
    vector<lli> score(n+1),ps(n+1,0);
    for(int i=1;i<=n;i++){cin>>score[i];ps[i]=score[i]+ps[i-1];}
    for(int i=n;i>0;i--){
        dp[i]=score[i];
        for(int j=i+1;j<=n;j++){
            dp[j]=max(ps[j-1]-ps[i-1]-dp[j-1]+score[j],score[i]-dp[j]+ps[j]-ps[i]);
        }
    }
    cout<<dp[n];
    return 0;
}