#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<int,int> pii;
vector<vi>adj;
vector<int>p;
vector<bool>visited;
 
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    p.resize(n+1,-1);
    visited.resize(n+1,false);
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    stack<int>s;
    vi ans;
    bool cycle=false;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i]=true;
            s.push(i);
            while(!s.empty()){
                int x=s.top();
                s.pop();
                for(int i=0;i<adj[x].size();i++){
                    int next=adj[x][i];
                    if(!visited[next]){
                        visited[next]=true;
                        p[next]=x;
                        s.push(next);
                    }
                    else{
                        if(p[x]!=next){
                            ans.pb(next);
                            ans.pb(x);
                            cycle=true;
                            break;
                        }
                    }
                }
                if(cycle)break;
            }
            
        }
        if(cycle)break;
    }
    if(cycle){
        int c=ans[1];
        while(c!=p[ans[0]]){
            ans.pb(p[c]);
            c=p[c];
        }
        ans.pb(ans[0]);
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    else cout<<"IMPOSSIBLE";
    return 0;
}