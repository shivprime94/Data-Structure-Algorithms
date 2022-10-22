// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
 
// void dijkstra(vector<vector<pair<int,int>>> &adj,vector<int> &d){
//     set<pair<int,int>> s;
//     s.insert({0,0});
//     while (!s.empty())
//     {
//     // cout<<"yes ";
//         auto n=*s.begin();
//         s.erase(n);
//         for(auto &i:adj[n.second]){
//             if(d[n.second]+i.second<d[i.first]){
//                 if(s.find({d[i.first],i.first})!=s.end()) s.erase({d[i.first],i.first});
//                 d[i.first]=d[n.second]+i.second;
//                 s.insert({d[i.first],i.first});
//             }
//         }
//     }
// }
 
// signed main(){
//     int n,m; cin>>n>>m;
//     // map<int,vector<pair<int,int>>> adj;
//     vector<vector<pair<int,int>>> adj(n);
//     for(int i=0;i<m;i++){
//         int a,b,c; cin>>a>>b>>c;
//         a--, b--;
//         auto it=lower_bound(adj[a].begin(), adj[a].end(), make_pair(b,0LL));
//         if(it!=adj[a].end()) it->second=c;
//         else adj[a].emplace_back(make_pair(b, c));
//     }
//     vector<int> d(n,LONG_MAX);
//     d[0]=0;
//     dijkstra(adj,d);
//     for(int i=0;i<n;i++) cout<<d[i]<<" ";
//     // for(auto i:adj[1]) cout<<i.first<<" ";
//     return 0;
// }
 
 
 
#include<bits/stdc++.h>
using namespace std;
#define int long
 
void dijkstra(map<int,vector<pair<int,int>>> &adj,vector<int> &d){
    set<pair<int,int>> s;
    s.insert({0,1});
    while (!s.empty())
    {
    // cout<<"yes ";
        auto n=*s.begin();
        s.erase(n);
        for(auto i:adj[n.second]){
            if(d[n.second]+i.second<d[i.first]){
                if(s.find({d[i.first],i.first})!=s.end()) s.erase({d[i.first],i.first});
                d[i.first]=d[n.second]+i.second;
                s.insert({d[i.first],i.first});
            }
        }
    }
}
 
signed main(){
    int n,m; cin>>n>>m;
    map<int,vector<pair<int,int>>> adj;
    map<pair<int,int>,int> index;
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        if(index.find({a,b})==index.end()){
            adj[a].push_back({b,c});
            index[{a,b}]=adj[a].size()-1;
        }
        else if(adj[a][index[{a,b}]].second>c){
            adj[a][index[{a,b}]].second=c;
        }
    }
    vector<int> d(n+1,LONG_MAX);
    d[1]=0;
    dijkstra(adj,d);
    for(int i=1;i<=n;i++) cout<<d[i]<<" ";
    // for(auto i:adj[1]) cout<<i.first<<" ";
    return 0;
}
