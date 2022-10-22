#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mod 1000000007
#define pb push_back
// #define MULTICASE
vector<int> path;
int printpath(vector<int> &parent,int i){
    if(i==0) return 0;
    int a=1+printpath(parent,parent[i]);
    path.push_back(i);
    return a;
}
 
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n+1);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> parent(n+1,-1),visited(n+1,-1);
    parent[1]=0;
    queue<int> q;
    q.push(1);
    visited[1]=1;
    while (!q.empty())
    {
        int x=q.front();
        // cout<<x<<" ";
        q.pop();
        for(auto i:v[x]){
            if(visited[i]==-1){
                visited[i]=1;
                q.push(i);
                parent[i]=x;
            }
        }
    }
    if(parent[n]==-1) cout<<"IMPOSSIBLE";
    else{
        cout<<printpath(parent,n)<<endl;
        for(auto i:path) cout<<i<<" ";
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifdef MULTICASE
       int t;
       cin>>t;
       while(t--)
    #endif
       solve();
       return 0;
}
