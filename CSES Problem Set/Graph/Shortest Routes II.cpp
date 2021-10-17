#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define ff first
#define ss second
#define MP make_pair

int n,m,q;
int g[505][505];
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 
    cin>>n>>m>>q;
    int x,y,z;
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]=1e18;
            if(i==j)g[i][j]=0;
        }
    }
 
    while(m--){
        cin>>x>>y>>z;
        g[x][y]=min(g[x][y],z);
        g[y][x]=min(g[y][x],z);
        g[x][y]=min(g[x][y],g[y][x]);
        g[y][x]=g[x][y];
    }
 
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                g[i][j]=min(g[i][j],g[j][i]);
                g[j][i]=g[i][j];
            }
        }
    }
 
    for(int i=0;i<q;i++){
        cin>>x>>y;
        cout<<((g[x][y]==1e18)?-1:g[x][y])<<endl;
    }
    return 0;
}
