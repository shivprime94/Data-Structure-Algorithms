#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const ll INF = 1e18;
template <typename T>
using minpq = priority_queue<T,vector<T>,greater<T>>;
 
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<ll> bes[n+1];
    vector<vector<pair<int,int>>> adj(n+1);
    auto dijkstra = [&](int s){
        minpq<pair<ll,int>> q;
        q.push({0,s});
        bes[1].push(0);
        while(!q.empty()){
            ll d = q.top().fi;
            int v = q.top().se;
            q.pop();
            if(bes[v].top() < d) continue;
 
            for(auto x : adj[v]){
                
                if(bes[x.fi].size() < k){
                    bes[x.fi].push(d + x.se);
                    q.push({d+x.se, x.fi});
                }
                else if(bes[x.fi].top() > d + x.se)
                {
                    bes[x.fi].pop();
                    bes[x.fi].push(d + x.se);
                    q.push({d+x.se, x.fi});
                }
            }
        }
    };
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
    }
    dijkstra(1);
    vector<ll> path;
    while(!bes[n].empty()){
        path.push_back(bes[n].top());
        bes[n].pop();
    }
    sort(path.begin(),path.end());
    for(auto i : path)
    cout << i << " ";
    return 0;
}
