// Coded By Shreyash Shrivastava

#include<bits/stdc++.h>
using namespace std;

bool CycleExist(int node,vector<int> &VIS,vector<int> ADJ[]){
    queue<pair<int,int>> Q;
    VIS[node]=1;
    Q.push(make_pair(node,-1));
    while(!Q.empty()){
        int v=Q.front().first;
        int u=Q.front().second;
        Q.pop();
        for(auto it:ADJ[v]){
            if(!VIS[it]){
                Q.push(make_pair(it,u));
                VIS[it]=1;
            }
            else if(u!=it){
                return true;
            }
        }
    }
    return false;
}


bool isCycle(int N,vector<int> ADJ[]){
    vector<int> VIS(N+1,0);
    for(int i=1;i<=N;i++){
        if(!VIS[i]){
            if(CycleExist(i,VIS,ADJ))return true;
        }
    }
    return false;
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
    if(isCycle(n,ADJ)){
        cout<<"Cycle Exist"<<endl;
    }
    else{
        cout<<"No Cycle"<<endl;
    }
    return 0;
}