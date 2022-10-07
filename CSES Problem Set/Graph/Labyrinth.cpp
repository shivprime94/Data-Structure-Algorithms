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
 
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    p.resize(n*m,-1);
    adj.resize(n*m);
    vector<string>g(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    int start,end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='A') start=i*m+j;
            if(g[i][j]=='B') end=i*m+j;
            if(g[i][j]=='.'||g[i][j]=='A'||g[i][j]=='B'){
                if(i+1<n&&(g[i+1][j]=='.'||g[i+1][j]=='A'||g[i+1][j]=='B')){
                    adj[i*m+j].pb((i+1)*m+j);
                    adj[(i+1)*m+j].pb(i*m+j);
                }
                if(j+1<m&&(g[i][j+1]=='.'||g[i][j+1]=='A'||g[i][j+1]=='B')){
                    adj[i*m+j].pb((i)*m+j+1);
                    adj[(i)*m+j+1].pb(i*m+j);
                }
            }
        }
    }
    bool found=false;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int c=q.front();
        q.pop();
        
        for(int i=0;i<adj[c].size();i++){
            int next=adj[c][i];
            if(p[next]==-1){
                p[next]=c;
                if(next==end){
                    found=true;
                    break;
                }
                q.push(next);
            }
        }
        if(found)break;
    }
    if(!found) cout<<"NO\n";
    else{
        stack<char>path;
        int c=end;
        p[start]=-1;
        while(p[c]!=-1){
            
            int parent=p[c];
            if(c+1==parent){
                path.push('L');}
            else if(c-1==parent){
                path.push('R');}
            else if(c+m==parent){
                path.push('U');}
            else if(c-m==parent){
                path.push('D');}
            c=parent;
        }
        cout<<"YES\n"<<path.size()<<"\n";
        while(!path.empty()){
            cout<<path.top();path.pop();
            
        }
    }
    
    
    return 0;
}