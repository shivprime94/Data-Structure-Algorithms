#include<bits/stdc++.h>
using namespace std;
 
#define pr(x) cout<<x<<'\n'
#define ll long long int
#define endl '\n'
#define vi vector<int> 
#define vl vector<ll> 
#define vb vector<bool> 
#define vvi vector<vector<int>  >
#define all(v) v.begin(),v.end()
#define MD 1000000007 //998244353
#define pb push_back
#define repi(i,a) for(int i = 0; i < (a); i++)
#define pii pair<int,int>
#define se second
#define fi first
 
ll binpow(ll a,ll b){	if(a==0) return 0; if(b==0) return 1;ll ans=1;while(b>0){if(b&1) ans=ans*a; a=a*a; b=b>>1;}	return ans;}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	 int q1;cin>>q1;while(q1--){
		int n;cin>>n;int mn=1e9;
		vi a(n);repi(i,n) {cin>>a[i];mn=min(mn,a[i]);}
		vi g;
		for(auto t:a) if(t!=mn) g.pb(t-mn);
		if(g.size()==0) pr(-1);
		else{
			int k=g[0];
			repi(i,g.size()-1) k=__gcd(g[i+1],k); 
			pr(k);
		}
		
		
	}
	
return 0;
}
