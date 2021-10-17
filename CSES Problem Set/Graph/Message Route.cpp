#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
 
int main(){
    int n, m;
    cin >> n >> m; 
    vector<vector<int>> adj(n+1);
    while(m--){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<int> ans, vis(n+1), P(n+1);
    bool ok = false;
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        //cout << v << " ";
        if(v == n)
        ok = true;
 
        for(auto u : adj[v]){
            if(vis[u]) continue;
            P[u] = v;
            vis[u] = 1;
            q.push(u);
        }
    }
    int cnt = 0;
    function<void(int)> print = [&](int x){
        if(x == 1)
        {
            cout << cnt+1 << "\n1 ";
            return;
        }
        cnt++;
        print(P[x]);
        cout << x << " ";
    };
    if(ok){
       print(n);
    }
    else cout << "IMPOSSIBLE";
    return 0;
}
