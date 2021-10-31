#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
#define mod 1000000007
typedef vector<int> vi;
typedef long long int lli;
typedef pair<lli,lli> pii;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    lli n,ans=0;
    cin>>n;
    vector<pair<lli,pii>>c(n);
    for(int i=0;i<n;i++){
       lli x,y,z; 
       cin>>x>>y>>z;
       c[i]={y,{x,z}};
    }
    sort(c.begin(),c.end());
    vector<pii> best;
    best.pb({c[0].first,c[0].second.second});
    for(int i=1;i<n;i++){
        lli ed=c[i].first,st=c[i].second.first,cur=c[i].second.second;
        lli prevbest=lower_bound(best.begin(),best.end(),mp(st,(lli)0))-best.begin()-1;
        if(prevbest==-1){
            if(best[i-1].second>cur)best.pb(best[i-1]);
            else{
                best.pb({ed,cur});
            }
        }
        else{
            best.pb({ed,cur+best[prevbest].second});
            if(best[i-1].second>best[i].second)best[i]=best[i-1];
        }
    }
    cout<<best[n-1].second;
    return 0;
}