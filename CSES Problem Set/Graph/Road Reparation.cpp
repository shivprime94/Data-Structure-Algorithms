#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define ff first
#define ss second
#define MP make_pair
#define int long long
 
struct UnionFind{
    int n,set_size,*parent,*rank;
    UnionFind(){}
    UnionFind(int a){
        n=set_size=a;
        parent=new int[n+1];
        rank=new int[n+1];
        for(int i=1;i<=n;++i)
            parent[i]=i,rank[i]=1;
    }
    int find(int x){
        if(x!=parent[x])return parent[x]=find(parent[x]);
        return x;
    }
    void merge(int x,int y){
        int xroot=find(x);
        int yroot=find(y);
        if(xroot!=yroot){
            if(rank[xroot]>=rank[yroot]){
                parent[yroot]=xroot;
                rank[xroot]+=rank[yroot];
            }else{
                parent[xroot]=yroot;
                rank[yroot]+=rank[xroot];
            }
            set_size-=1;
        }
    }
    //void reset(){set_size=n;for(int i=1;i<=n;i++)parent[i]=i,rank[i]=1;}
    //int size(){return set_size;}
    //void print(){for(int i=1;i<=n;++i){cout<<i<<"->"<<parent[i]<<endl;}}
};
 
//we need sorted edge list
vector<ii> g[100100];//final MST tree
vector<pair<int,ii> > edgelist;
 
void solve(){
    int n,m;cin>>n>>m;
    UnionFind uf(n);
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        edgelist.push_back(MP(c,MP(a,b)));
    }
    sort(edgelist.begin(),edgelist.end());
    int mst_cost=0,cnt=0;
 
    for(int jj=0;jj<edgelist.size();jj++){
        pair<int,ii> v=edgelist[jj];
        int x=v.ss.ff;
        int y=v.ss.ss;
        if(uf.find(x)!=uf.find(y)){
            cnt++;
            mst_cost+=v.ff;
            //g[x].push_back(MP(y,v.ff));
            //g[y].push_back(MP(x,v.ff));
            uf.merge(x,y);
        }
    }
    if(cnt!=(n-1)){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<mst_cost<<endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    solve();
}
