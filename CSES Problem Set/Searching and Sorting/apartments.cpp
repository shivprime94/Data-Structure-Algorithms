#include<bits/stdc++.h>
using namespace std;

#define db(x) cout<<x<<'\n'
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define repi(i,n) for(int i=0;i<(n);++i)
#define ll long long int
#define endl '\n'
#define vi vector<int> 
#define vl vector<ll> 
#define vb vector<bool> 
#define vvi vector<vector<int>  >
#define err(t) cout<<"Error : "<<t<<endl;
#define all(v) v.begin(),v.end()
#define pb push_back
#define rep(i,a,b) for(ll i = a; i <= (b); i++)

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int n,m,k;cin>>n>>m>>k;
	vi a(n);repi(i,n) cin>>a[i];sort(all(a));
	vi b(m);repi(i,m) cin>>b[i];sort(all(b));
	int i=0;int j=0;int ans=0;
	while(i!=n&&j!=m){
		if(b[j]+k<a[i]) j++;
		else if(b[j]-k>a[i]) i++;
		else i++,j++,ans++;
	}
	db(ans);

return 0;
}

