#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> dp(n+1), in(n+1);
    vector<vector<int>> adj(n+1);
    auto topo = [&](){
        queue<int> q;
        for(int s = 1; s <= n; s++){
        if(in[s] == 0){
        q.push(s);
        }
      } 
      dp[1] = 1;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto u : adj[v])
            {
                in[u]--;
                if(in[u] == 0)
                q.push(u);
 
                dp[u] += dp[v];
                dp[u] %= mod; 
            }
        }
    };
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        in[y]++;
        adj[x].push_back(y);
    }
 
    topo();
    cout << dp[n];
    return 0;
}
