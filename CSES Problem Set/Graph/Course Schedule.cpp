#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<lli,lli> pii;
vector<vi>adj;
vector<int>p;
vector<bool>visited,instack;
vi topsort;
int cycle =0,st=0;
void dfs (int c){
    visited[c]=instack[c]=true;
    if(cycle)return;
    for(int i=0;i<adj[c].size();i++){
            int next=adj[c][i];
             if(instack[next]&&!cycle){
                    cycle=next;
                    st=c;
                 
             }
            if(!visited[next]){
                visited[next]=true;
                p[next]=c;
                dfs(next);
            }
            
             
        }
        instack[c]=false;
        if(cycle)return;
        topsort.pb(c);
       
}
 
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    adj.resize(n+1),p.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }
    
    visited.resize(n+1,false),instack.resize(n+1,false);
 
    for(int i=1;i<=n;i++){
        if(!visited[i])
            dfs(i);
        if(cycle)break;
    }
    if(!cycle){
       reverse(topsort.begin(),topsort.end());
       for(int u:topsort) cout<<u<<" ";
        
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
  
    return 0;
}