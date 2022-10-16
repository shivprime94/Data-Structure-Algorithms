// Coded by Shreyash Shrivastava
/* I have used Kahn's algorithm of topological sorting for this problem*/


#include<bits/stdc++.h>

using namespace std;
bool isCycle(int N,vector<int> ADJ[]){
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
    int cnt=0;
    while(!Q.empty()){
        cnt++;
        int node=Q.front();
        Q.pop();
        for(auto it:ADJ[node]){
            InDegree[it]--;
            if(InDegree[it]==0){
                Q.push(it);
            }
        }
    }
    if(cnt==N) return false;
    return true;
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
        cout<<"No Cycle Exist"<<endl;
    }
    return 0;
}