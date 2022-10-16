#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize(3, "Ofast", "inline")
 
#include<bits/stdc++.h> 
using namespace std;
using namespace chrono;
#define endl "\n"
 
#define _USE_MATH_DEFINES
#include <cmath>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
 
 
#define int long long int
#define pb push_back
#define mk make_pair
#define ppb pop_back
#define pf  push_front
#define ppf  pop_front
#define all(x) (x).begin(),(x).end()
#define ub upper_bound
#define lb lower_bound
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
 
int const N=3*1e5+10;
//int const INF=1e18;
int mod=1e9+7;
int mod1=998244353;
const int INF=1e4;
 
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
int n,m;
vector<int>g[N];
vector<bool>vis;
vector<int>col;
 
bool dfs(int v){
  vis[v]=1;
 // cout<<v<<" ";
  for(auto &ch: g[v]){
    if(col[ch]==col[v])return false;
    if(vis[ch])continue;
    //cout<<ch<<" ";
    col[ch]=1-col[v];
    if(!dfs(ch))return false;
  }
  
  return true;
}
 
 
void solve(){
 cin>>n>>m;
 vis.resize(n+1,0);
 col.resize(n+1,-1);
 vector<vector<int>>edge;
 rep(i,0,m){
  int u,v;
  cin>>u>>v;
  g[u].pb(v);
  g[v].pb(u);
  edge.pb({u,v});
 }
 col[1]=0;
 if(!dfs(1)){
  cout<<"NO"<<endl;
  return;
 }
 
 cout<<"YES"<<endl;
 //string ans="";
// rep(i,1,n)cout<<col[i]<<" ";
 //cout<<endl;
 for(auto &x: edge){
  if(col[x[0]]==0 && col[x[1]]==1)cout<<"0";
  else cout<<"1";
 }
 //cout<<ans<<endl;
 //rep(i,1,n)cout<<col[i]
 return;
}
 
 
 
 
signed main(){
  #ifndef ONLINE_JUDGE
  freopen("INPUT1.txt","r",stdin);
  freopen("out1.txt","w",stdout);
  #endif 
  
  
    fastio();
    auto start1 = high_resolution_clock::now();
    int t=1;
    // cin>>t;
    // precompute();
    
    //fill_dp();
    while(t--){
      solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
    cout << "Time: " << duration . count() / 1000 <<"ms"<<endl;
    #endif
  
  return 0;
}