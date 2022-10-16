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
vector<bool>vis(N,0);
vector<int>col;
int isCycle;
void dfs(int v){
  vis[v]=1;
  if(g[v].size()!=2)isCycle=0;
  
  for(auto &ch: g[v]){
    if(vis[ch])continue;
    
    dfs(ch);
  }
}
 
void solve(){
 cin>>n>>m;
 vis.resize(n+1);
 rep(i,0,m){
  int u,v; 
  cin>>u>>v;
  g[u].pb(v);
  g[v].pb(u);
 }
 
 int ans=0;
 rep(i,1,n){
  if(vis[i])continue;
  
  isCycle=1;
  dfs(i);
  if(isCycle)ans++;
 }
 
 cout<<ans<<endl;
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
 
