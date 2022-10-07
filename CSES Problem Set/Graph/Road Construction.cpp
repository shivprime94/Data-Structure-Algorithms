#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const ll INF = 1e18;
int mxs = 0;
struct DSU{
    vector<int> P, size;
    DSU(int n)
    {
        P.assign(n+1,0);
        size.assign(n+1,1);
        for(int i = 1; i <= n; i++)
        {
            P[i] = i;
        }
    }    
        int root(int x)
        {
            if(x == P[x])
            return x;
            return P[x] = root(P[x]);
        }
        int Union(int x, int y)
        {
            int a = root(x);
            int b = root(y);
            if(a == b)
            return 0;
            size[b] += size[a];
            mxs = max(mxs, size[b]);
            P[a] = b;
            return 1;
        }
    
};
 
int main(){
    int n, m;
    cin >> n >> m;
    DSU D(n);
    int cnt = 0;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        int p = D.Union(x,y);
        cnt += p;
        cout << n - cnt << " " << mxs << "\n"; 
    }
    return 0;
}
