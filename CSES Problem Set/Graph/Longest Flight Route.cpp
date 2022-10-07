#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<int,lli> pii;
vector<vi>adj;
vector<int>p;
vi topsort;
vector<bool>visited;
void dfs (int c){
  
    visited[c]=true;
    for(int i=0;i<adj[c].size();i++){
            int next=adj[c][i];
        
            if(!visited[next]){
                visited[next]=true;
                
                dfs(next);
            }
            
             
        }
        
        topsort.pb(c);
       
} 
 
 
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    adj.resize(n+1),visited.resize(n+1,false),p.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }
    vector<lli>dist(n+1,-inf);
    dfs(1);
    reverse(topsort.begin(),topsort.end());
    dist[1]=1;
    for(int u:topsort){
        
        for(int next:adj[u]){
           if(dist[next]<dist[u]+1){
               dist[next]=dist[u]+1;
               p[next]=u;
           }
        }
    }
    if(dist[n]==-inf)cout<<"IMPOSSIBLE";
    else {
        cout<<dist[n]<<"\n";
        int pre =n;
        vi path;
        while(pre!=-1){
            path.pb(pre);
            pre=p[pre];
        }
        reverse(path.begin(),path.end());
        for(int p:path) cout<<p<<" ";
    }
    return 0;
}