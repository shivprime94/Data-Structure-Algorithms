// Coded By Shreyash Shrivastava

#include<bits/stdc++.h>

using namespace std;

void DeapthFirstSearch(int node,vector<int> ADJ[],vector<int> &VIS,vector<int> &DFSresult){
    DFSresult.push_back(node);
    VIS[node]=1;
    for(auto it:ADJ[node]){
        if(!VIS[it]){
            DeapthFirstSearch(it,ADJ,VIS,DFSresult);
        }
    }
}
vector<int> DFS(int N,vector<int> ADJ[]){
    vector<int> DFSresult;
    vector<int> VIS(N+1,0);
    for(int i=1;i<=N;i++){
        if(!VIS[i]){
            DeapthFirstSearch(i,ADJ,VIS,DFSresult);
        }
    }
    return DFSresult;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> ADJ[n+1];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        ADJ[u].push_back(v);
        ADJ[v].push_back(u);
    }
    for(auto it:DFS(n,ADJ)){
        cout<<it<<" ";
    }
    return 0;
}