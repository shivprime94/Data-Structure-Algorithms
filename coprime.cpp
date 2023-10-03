#include<bits/stdc++.h>
using namespace std;
//#define M_PI 3.1415926535897932384
#define int long long int
#define pb push_back
#define mk make_pair
#define ppb pop_back
#define pf  push_front
#define ppf  pop_front
#define all(x) (x).begin(),(x).end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define sz(x)  (int)((x).size())
#define fr first
#define sc second
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define endl "\n"
int const N=510;
// vector<int> graph[N];
// vector<int>depth(N);
// int par[N];
// int siz[N];
// vector<pii> del;
// vector<int> leader;
// vector<pii> edge;
 
 
 void solve(){
 char arr[8][8];
 rep(i,0,8){
  rep(j,0,8)cin>>arr[i][j];
 }
 rep(i,0,8){
  if(arr[i][0]=='R'){
    int ct=0;
    rep(j,0,8){
      if(arr[i][j]=='R'){
        ct++;
      }
      if(ct==8){
        cout<<"R"<<endl;
        return;
      }
    }
  }
 }
 rep(i,0,8){
  if(arr[0][i]=='B'){
    int ct=0;
    rep(j,0,8){
      if(arr[j][i]=='B'){
        ct++;
      }
      if(ct==8){
        cout<<"B"<<endl;
        return;
      }
    }
  }
 }
 return;
}
 
 
 
 
 
 
 
    
 
 
 
 
 
   signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif 
 	int t=1;
   cin>>t;
     while(t--){
	 	solve();
	}
   	return 0;
}
