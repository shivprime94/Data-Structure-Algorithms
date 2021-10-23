#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const ll INF = 1e18;
struct Edge{
    int x, y;
    ll z;
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edge;
    
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        edge.push_back({x,y,z});
    }
    vector<int> P(n+1,-1);
    vector<ll> D(n+1,INF);
    for(int i = 1; i <= n-1; i++){
        for(auto e : edge){
            if(D[e.y] > D[e.x] + e.z)
            {
               D[e.y] = D[e.x] + e.z;
               P[e.y] = e.x;
            }
        }
    }
    int x = -1;
        for(auto e : edge){
            if(D[e.y] > D[e.x] + e.z){
               x = e.y;
               break;  
            }
        }
    if(x != -1)    
    for(int i = 0; i < n; i++)
    {
        x = P[x];
    }   
    int c = x; 
    vector<int> cycle;    
    do
    {
        if(x == -1)
        break;
        cycle.push_back(x);
        x = P[x];
    } while(x != c);
 
    if(c == -1){
        cout << "NO";
    }
    else{ 
        cout << "YES\n";
        assert(cycle.size()>0);
    reverse(cycle.begin(),cycle.end());
    cycle.push_back(cycle[0]);
    for(auto i : cycle)
    cout  << i << " ";
    }
    return 0;
}
