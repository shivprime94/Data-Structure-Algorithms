#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
template<typename T>
using minpq = priority_queue<T,vector<T>,greater<T>>;
typedef long long ll;
const ll INF = 1e15; 
int main(){
    int n, m;
    cin >> n >> m; 
    vector<pair<pair<int,int>,int>> edge;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w; 
        edge.pb(make_pair(make_pair(x,y),w));
        adj[x].pb(y);
        //adj[y].pb({x,w});
    }
    vector<ll> D(n+1,-INF);
    // Bellman Ford
    D[1] = 0;
    for(int j = 0; j < n-1; j++){
        for(auto i : edge){
            D[i.fi.se] = max(D[i.fi.se],D[i.fi.fi]+i.se);
        }
    }
    vector<bool> bad(n+1),vis1(n+1),vis(n+1);
    for(int j = 0; j < n-1; j++)
    for(auto i : edge){
     if(D[i.fi.se] < D[i.fi.fi] + i.se)
         bad[i.fi.se] = true;
        D[i.fi.se] = max(D[i.fi.se],D[i.fi.fi]+i.se); 
    } 
    
    bool ok = false;
    function<void(int)> dfs1 = [&](int v){
        vis1[v] = 1;
        if(v == n)
        ok = true;
        for(auto u : adj[v]){
            if(!vis1[u])
            dfs1(u);
        }
    };
    function<void(int)> dfs = [&](int v){
        vis[v] = 1;
        if(bad[v])
          dfs1(v);
        for(auto u : adj[v]){
            if(!vis[u])
            dfs(u);
        }
    };
    dfs(1);
    if(ok){
        cout << -1;
    }
    else cout << D[n];
    return 0;
}
