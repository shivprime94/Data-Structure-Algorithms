#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<int,int> pii;
vector<vi>adj;
vector<bool>visited;
void dfs(int curr){
    for(int i=0;i<adj[curr].size();i++){
        int next=adj[curr][i];
        if(!visited[next]){
            visited[next]=true;
            dfs(next);
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    visited.resize(n*m,false);
    adj.resize(n*m);
    vector<string>g(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='.'){
                if(i+1<n&&g[i+1][j]=='.'){
                    adj[i*m+j].pb((i+1)*m+j);
                    adj[(i+1)*m+j].pb(i*m+j);
                }
                if(j+1<m&&g[i][j+1]=='.'){
                    adj[i*m+j].pb((i)*m+j+1);
                    adj[(i)*m+j+1].pb(i*m+j);
                }
            }
        }
    }
    int ans =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!(visited[i*m+j])&&g[i][j]=='.'){
                visited[i*m+j]=true;
                dfs(i*m+j);
                ans++;
            }
       }
    }
    cout<<ans;
    
    return 0;
}