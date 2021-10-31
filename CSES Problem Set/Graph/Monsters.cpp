#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<int,int> pii;
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vi>adj;
    vi p;
    p.resize(n*m,-1);
    adj.resize(n*m);
    vector<string>g(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    int start;
    vi monster;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='A') start=i*m+j;
            if(g[i][j]=='M') monster.pb(i*m+j);
            if(g[i][j]=='.'||g[i][j]=='A'||g[i][j]=='M'){
                if(i+1<n&&(g[i+1][j]=='.'||g[i+1][j]=='A'||g[i+1][j]=='M')){
                    adj[i*m+j].pb((i+1)*m+j);
                    adj[(i+1)*m+j].pb(i*m+j);
                }
                if(j+1<m&&(g[i][j+1]=='.'||g[i][j+1]=='A'||g[i][j+1]=='M')){
                    adj[i*m+j].pb((i)*m+j+1);
                    adj[(i)*m+j+1].pb(i*m+j);
                }
            }
        }
        
    }
    vector<vi>dist(2,vi(n*m,1e9));
    vector<vector<bool>>visited(2,vector<bool>(n*m,false));
    queue<int>q;
    for(int i=0;i<monster.size();i++) {q.push(monster[i]),visited[1][monster[i]]=true;dist[1][monster[i]]=0;}
    while(!q.empty()){
        int c=q.front();
        // visited[1][c]=true;
        q.pop();
        for(int i=0;i<adj[c].size();i++){
            int next=adj[c][i];
            if(!visited[1][next]){
                visited[1][next]=true;
                dist[1][next]=dist[1][c]+1;
                q.push(next);
            }
        }
    }
    q.push(start);
    dist[0][start]=0;
    visited[0][start]=true;
     while(!q.empty()){
        int c=q.front();
        q.pop();
        for(int i=0;i<adj[c].size();i++){
            int next=adj[c][i];
            if(!visited[0][next]){
                visited[0][next]=true;
                p[next]=c;
                dist[0][next]=dist[0][c]+1;
                q.push(next);
            }
        }
    }
    int ex=-1;
    for(int i=0;i<m;i++){
        if(dist[0][i]<dist[1][i]) {
            ex=i;
        }
        if(dist[0][(n-1)*m+i]<dist[1][(n-1)*m+i]) {
            ex=(n-1)*m+i;
        }
    }
    for(int i=0;i<n;i++){
        if(dist[0][i*m]<dist[1][i*m]){
          ex=i*m;  
        } 
        if(dist[0][i*m+m-1]<dist[1][i*m+m-1]) {
            ex=i*m+m-1;
           
        }
    }
    if(ex==-1) cout<<"NO";
    else{
        string path;
        int d[]={m,1,-m,-1};
        char m[]={'D','R','U','L'};
        while(p[ex]!=-1){
            int change=ex-p[ex];
            for(int i=0;i<4;i++){
                if(change==d[i])path.pb(m[i]);
            }
            ex=p[ex];
        }
        cout<<"YES\n"<<path.size()<<"\n";
        reverse(path.begin(),path.end());
        cout<<path;
    }
    
    return 0;
}