#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const ll INF = 1e18;
template <typename T>
using minpq = priority_queue<T,vector<T>,greater<T>>;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1), adj1(n+1);
    vector<int> in(n+1);
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj1[y].push_back({x,z});
    }
    vector<ll> d1(n+1,INF), dn(n+1,INF);
    vector<int> P(n+1);
    auto dijkstra = [&](int s, vector<ll> &D, vector<vector<pair<int,int>>> &adj, int a){
        minpq<pair<ll,int>> q;
        q.push({0,s});
        D[s] = 0;
        while(!q.empty()){
            ll d = q.top().fi;
            int v = q.top().se;
            q.pop();
            
            if(D[v] != d)
            continue;
 
            for(auto x : adj[v]){
                ll nxt = d + x.se;
                if(nxt < D[x.fi])
                {
                    D[x.fi] = nxt;
                    q.push({d+x.se,x.fi});
                    if(a == 0)
                    P[x.fi] = v;     
                }
            }
        }
    };
    dijkstra(1,d1,adj,0);
    dijkstra(n,dn,adj1,1);
    vector<vector<pair<int,int>>> G(n+1);
    auto make_dag = [&](){
        for(int v = 1; v <= n; v++)
        {
            for(auto x : adj[v])
            {
                int u = x.fi;
                int d = x.se;
                if(d1[v] + d +dn[u] == d1[n])
                {
                        G[v].pb({u,d});
                }
            }
        }
    };
    make_dag();
    vector<ll> dp(n+1);
    vector<ll> h0(n+1,INF), h1(n+1,-INF);
    auto topo2 = [&](vector<int> in){
        queue<int> q;
        for(int i = 1; i <= n; i++)
        {
            if(in[i] == 0){
                q.push(i);
            }
        }
        dp[1] = 1;
        h0[1] = h1[1] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto x : G[v]){
                int u = x.fi;
                int d = x.se;
                in[u]--;
                if(in[u] == 0)
                {
                    q.push(u);
                }
                dp[u] += dp[v];
                dp[u] %= mod;
                h0[u] = min(h0[u], h0[v] + 1);
                h1[u] = max(h1[u], h1[v] + 1);
            }
        }
    };
    for(int i = 1; i <= n; i++)
    {
       for(auto u : G[i])
       in[u.fi]++;
    }
    topo2(in);   
    cout << d1[n] << " " << dp[n] << " " << h0[n] << " " << h1[n];
    return 0;
}
