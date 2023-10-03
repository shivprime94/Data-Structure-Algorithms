// Coded By Shreyash Shrivastava

#include<bits/stdc++.h>
using namespace std;

void BreadthFirstSearch(int N,vector<int> ADJ[],vector<int> &BFS){
    queue<int> Q;
    vector<int> VIS(N+1,0);
    for(int i=1;i<=N;i++){
        if(!VIS[i]){
            Q.push(i);
            VIS[i]=1;
            while(!Q.empty()){
                int node=Q.front();
                Q.pop();
                BFS.push_back(node);
                for(auto it:ADJ[node]){
                    if(!VIS[it]){
                    Q.push(it);
                    VIS[it]=1;
                    }
                }
            }
        }
    }
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
    vector<int> BFS;
    BreadthFirstSearch(n,ADJ,BFS);
    for(auto it:BFS){
        cout<<it<<" ";
    }
    return 0;
}