#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<int,int> pii;
vector<vi>adj;
vector<int>col;
 
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    col.resize(n+1,-1);
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bool found =false;
    for(int i=1;i<=n;i++){
            if(col[i]==-1){
                queue<int>q;
                q.push(i);
                col[i]=0;
                while(!q.empty()){
                    int c=q.front();
                    q.pop();
                    for(int i=0;i<adj[c].size();i++){
                        int next=adj[c][i];
                        if(col[next]==-1){
                            col[next]=!col[c];
                            q.push(next);
                        }
                        else{
                            if(col[next]!=(!col[c])){
                                found=true;
                                goto hell;
                            }
                        }
                        
                    }
                    
                }
            }
    }
    hell:
    if(found)cout<<"IMPOSSIBLE";
    else{
        for(int i=1;i<=n;i++){
            cout<<col[i]+1<<" ";
        }
    }
    
    
    return 0;
}