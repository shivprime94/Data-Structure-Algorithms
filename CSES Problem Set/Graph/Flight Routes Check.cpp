#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
void dfs(int v, vector<vector<int>> &adj, vector<int> &can){
        can[v] = 1;
        for(auto u : adj[v])
        {
            if(!can[u])
              dfs(u,adj,can);
        }
    }
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1), adj1(n+1);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj1[y].pb(x);
    }
    vector<int> can(n+1), can1(n+1);
    dfs(1,adj,can);
    dfs(1,adj1,can1);
    for(int i = 1; i <= n; i++)
    {
        if(can[i] == 0)
        {
            cout << "NO\n";
            cout << 1 << " " << i;
            return 0;
        }
        else if(can1[i] == 0)
        {
            cout << "NO\n";
            cout << i << " " << 1;
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
