// Coded By Shreyash Shrivastava

#include<bits/stdc++.h>
using namespace std;

bool CycleExist(int node,int parent,vector<int> &VIS,vector<int> ADJ[]){
    VIS[node]=1;
    for(auto it:ADJ[node]){
        if(!VIS[it]){
            if(CycleExist(it,node,VIS,ADJ))return true;
        }
        else if(it!=parent){
            return true;
        }
    }
    return false;
}


bool isCycle(int N,vector<int> ADJ[]){
    vector<int> VIS(N+1,0);
    for(int i=1;i<=N;i++){
        if(!VIS[i]){
        if(CycleExist(i,-1,VIS,ADJ))return true;
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