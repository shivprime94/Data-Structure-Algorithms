#include<bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    int m,n,q; cin>>m>>n>>q;
    vector<vector<pair<int,int>>> g(m);
    vector<vector<int>> dist(m,vector<int>(m,LLONG_MAX));
    for (int i = 0; i < n; i++)
    {
        int a,b,c; cin>>a>>b>>c;
        g[a-1].push_back({b-1,c});
        g[b-1].push_back({a-1,c});
        dist[a-1][b-1]=min(dist[a-1][b-1],c);
        dist[b-1][a-1]=min(dist[b-1][a-1],c);
    }
    for (int i = 0; i < m; i++)
    {
        dist[i][i]=0;
    }
 
    for (int k = 0; k < m; k++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]>0 ? dist[i][k]+dist[k][j]:LLONG_MAX);
            }
        }
    }
 
    while (q--)
    {
        int x,y; cin>>x>>y;
        if(dist[x-1][y-1]<0 || dist[x-1][y-1]==LLONG_MAX) cout<<-1<<endl;
        else cout<<dist[x-1][y-1]<<endl;
    }
    
}
Share code to others
Test details
Test 1
Verdict: ACCEPTED

