// Coded By Shreyash Shrivastava

#include<bits/stdc++.h>

using namespace std;

vector<int> TS(int N,vector<int> ADJ[]){
    queue<int> Q;
    vector<int> InDegree(N+1,0);
    for(int i=1;i<=N;i++){
        for(auto it:ADJ[i]){
            InDegree[it]++;
        }
    }
    for(int i=1;i<=N;i++){
        if(InDegree[i]==0){
            Q.push(i);
        }
    }
    vector<int> TOPO;
    while(!Q.empty()){
        int node=Q.front();
        Q.pop();
        TOPO.push_back(node);
        for(auto it:ADJ[node]){
            InDegree[it]--;
            if(InDegree[it]==0){
                Q.push(it);
            }
        }
    }
    return TOPO;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> ADJ[n+1];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        ADJ[u].push_back(v);
    }
    for(auto it:TS(n,ADJ)){
        cout<<it<<" ";
    }
    return 0;
}