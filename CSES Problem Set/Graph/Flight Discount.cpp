#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const ll INF = 1e18;
template <typename T>
using minpq = priority_queue<T,vector<T>,greater<T>>;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<ll> D(n+1), dp1(n+1,INF), // disc taken
    dp2(n+1,INF);     // disc not taken
    auto dijkstra = [&](int s){
        minpq<pair<pair<ll,ll>,int>> q;
        q.push({{0,0},s});
        dp1[s] = dp2[s] = 0; 
 
        while(!q.empty()){
            ll d1 = q.top().fi.fi;
            ll d2 = q.top().fi.se;
            int v = q.top().se;
            q.pop();
            
            if(dp1[v] < d1 && dp2[v] < d2)
            continue;
            for(auto x : adj[v]){
                ll a = min(d1 + x.se, d2 + x.se/2);
                ll b = d2 + x.se; 
                if(dp1[x.fi] > a || dp2[x.fi] > b){
                dp1[x.fi] = min(dp1[x.fi],a);
                dp2[x.fi] = min(dp2[x.fi],b);
                q.push({{dp1[x.fi],dp2[x.fi]},x.fi});
              }        
                
            }
        } 
    };
    for(int i = 0; i < m; i++){
        int x, y, c;
        cin >> x >> y >> c;
        adj[x].push_back({y,c});
    }
    dijkstra(1);
    cout << dp1[n];
    return 0;
}
