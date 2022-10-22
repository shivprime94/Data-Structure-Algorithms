#include<bits/stdc++.h>
using namespace std;
 
void dfs(int n,map<int,vector<int>> &adj,vector<int> &v){
    v[n]=1;
    for(auto i:adj[n]){
        if(v[i]==-1) dfs(i,adj,v);
    }
}
 
int main(){
    int n,m; cin>>n>>m;
    map<int,vector<int>> adj;
    while (m--)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> v(n+1,-1);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if(v[i]==-1){
            ans.push_back(i);
            dfs(i,adj,v);
        }
    }
    cout<<ans.size()-1<<endl;;
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    return 0;
}
