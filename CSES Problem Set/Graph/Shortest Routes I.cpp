#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<lli,lli> pii;
vector<vi>adj;
vector<int>p;
 
int main(){
  ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    lli n,m;
    cin>>n>>m;
    vector<vector<pii>>adj(n+1);
    for(int i=0;i<m;i++){
        lli x,y,c;
        cin>>x>>y>>c;
        adj[x].pb(mp(y,c));
    }
    vector<lli>dist(n+1,inf);
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    dist[1]=0;
    pq.push(mp(0,1));
    while(!pq.empty()){
        pii c=pq.top();
        pq.pop();
        if(dist[c.second]<c.first)continue;
        for(int i=0;i<adj[c.second].size();i++){
            int next=adj[c.second][i].first;
            int cost=adj[c.second][i].second;
            if(dist[next]>c.first+cost){
                dist[next]=c.first+cost;
                pq.push(mp(dist[next],next));
                
            }
        }
    
    }
    for(int i=1;i<n+1;i++)cout<<dist[i]<<" ";
    
    
    
    return 0;
}