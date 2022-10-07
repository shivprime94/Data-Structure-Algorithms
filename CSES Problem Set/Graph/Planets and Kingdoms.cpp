#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1), rev(n+1);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        rev[y].pb(x);
    }
    vector<int> order;
    vector<int> ans(n+1), vis(n+1);
    function<void(int)> dfs = [&](int v){
        vis[v] = 1;
        for(auto u : adj[v])
        {
            if(!vis[u])
              dfs(u);
        }
        order.pb(v);
    };
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        dfs(i);
    }
    reverse(order.begin(),order.end());
    int i = 0;
    function<void(int,int)> dfs1 = [&](int v, int i){
        ans[v] = i;
        for(auto u : rev[v])
        if(!ans[u])
        dfs1(u,i);
    };
    for(auto u : order)
    {
        if(!ans[u])
        {
            dfs1(u,++i);
        }
    }   
    cout << i << "\n";
    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
