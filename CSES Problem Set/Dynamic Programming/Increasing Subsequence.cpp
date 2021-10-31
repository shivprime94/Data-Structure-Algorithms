#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
#define mod 1000000007
typedef vector<int> vi;
typedef long long int lli;
typedef pair<lli,int> pii;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,ans=0;
    cin>>n;
    vi c(n);
    for(int i=0;i<n;i++)cin>>c[i];
    vi dp;
   
    for(int i=0;i<n;i++){
        auto p=lower_bound(dp.begin(),dp.end(),c[i]);
        if(p==dp.end()) dp.pb(c[i]);
        else *p=c[i];
    }
    cout<<dp.size();
    
    return 0;
}