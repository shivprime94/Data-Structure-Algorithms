// Coded By Shreyash Shrivastava

#include<bits/stdc++.h>
using namespace std;

void TopologicalSort(int node,vector<int> &VIS,vector<int> ADJ[],stack <int> &st){
    VIS[node]=1;
    for(auto it:ADJ[node]){
        if(!VIS[it]){
        TopologicalSort(it,VIS,ADJ,st);
        }
    }
    st.push(node);
}


vector<int> TS(int N,vector<int> ADJ[]){
    stack<int> st;
    vector<int> VIS(N+1,0);
    vector<int> Topo;
    for(int i=1;i<=N;i++){
        if(!VIS[i]){
        TopologicalSort(i,VIS,ADJ,st);
        }
    }
    while(!st.empty()){
        Topo.push_back(st.top());
        st.pop();
    }
    return Topo;
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