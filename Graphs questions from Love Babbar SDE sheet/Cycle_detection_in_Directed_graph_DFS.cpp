// Coded By Shreyash Shrivastava

#include<bits/stdc++.h>
using namespace std;

bool CycleExist(int node,vector<int> &VIS,vector<int> &DFSVis,vector<int> ADJ[]){
    VIS[node]=1;
    DFSVis[node]=1;
    for(auto it:ADJ[node]){
        if(!VIS[it]){
            if(CycleExist(it,VIS,DFSVis,ADJ))return true;
        }
        else if(DFSVis[it]) return true;
    }
    DFSVis[node]=0;
    return false;
}



bool isCycle(int N,vector<int> ADJ[]){
    vector<int> VIS(N+1,0);
    vector<int> DFSVis(N+1,0);
    for(int i=1;i<=N;i++){
        if(!VIS[i]){
        if(CycleExist(i,VIS,DFSVis,ADJ))return true;
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
    }
    if(isCycle(n,ADJ)){
        cout<<"Cycle Exist"<<endl;
    }
    else{
        cout<<"No Cycle"<<endl;
    }
    return 0;
}