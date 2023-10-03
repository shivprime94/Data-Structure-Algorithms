#include<bits/stdc++.h>
using namespace std;
 
//#include <cmath>
//#ifndef M_PI
   // #define M_PI 3.14159265358979323846
 
using namespace std;
#define int long long int
/*#define pb push_back
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
#define ppcll __builtin_popcountll*/
//int const p=1e5;
int const N= 1e3+3;
//int const INF=1e9 +7;
 //int dp[N];
 char mp[N][N];
 int vis[N][N];
 int n,m;
 //moves array
 vector<pair<int,int>>moves={{1,0},{0,1},{-1,0},{0,-1}};
 // checking the possible moves
 bool ispossible(int x, int y){
   return (x>=0 && x< n && y>=0 && y< m && mp[x][y]=='.') ;
 }
//implimenting the dfs algorithm
void dfs(int x,int y){
 
  vis[x][y]=1;
   for(auto p: moves){
      int ch_x = x + p.first;
      int ch_y = y + p.second;
      //checking of the visited commponent
      if(!ispossible(ch_x,ch_y) || vis[ch_x][ch_y]) continue;
         dfs(ch_x, ch_y); 
   }
   return;
 
}
 
 void solve() {
   cin>>n>>m;
   vector<string> v;
   int cnt=0;
   //memset(vis,-1,sizeof(vis));
   for(int i=0;i<n;i++){
      string s;
      cin>>s;
      v.push_back(s);
      }
   
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         mp[i][j]=v[i][j];
 
         
      }
         
   }
   for(int i=0;i<n;i++){
      for(int j =0;j<m;j++){
         if(mp[i][j]=='.'){
            if(vis[i][j]==1) continue;
            dfs(i,j);
            cnt++;
         }
      }
   }
 cout<<cnt<<endl;
 
 return;
}
 
 
 
 
 
 
signed main(){
   ios_base::sync_with_stdio(false); cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("mc.txt","r",stdin);
  freopen("text_case_pass_ho_kya.text","w",stdout);
  #endif 
  
   int t=1;
   //cin>>t;
   while(t--){
      solve();
    }
   return 0;
}
