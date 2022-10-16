// Coded By Shreyash Shrivastava

#include<bits/stdc++.h>
using namespace std;
//                 8        1---------9
//                 |        |
//                 |        |
//                 |        |
//                 |        |
//                 6--------2---------3
//                          |         |
//                          |         |
//                          |         |
//                          |         |
//                 7--------4         5





int main(){
    int n,m; //n=>number of nodes AND m=>number of edges
    cin>>n>>m;
    vector<int> ADJ[n+1];
    //Creating the graph
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        ADJ[u].push_back(v);
        ADJ[v].push_back(u);
    }
    //Displaying a graph
    for(int i=1;i<=n;i++){
        for(auto it:ADJ[i]){
            cout<<i<<"->"<<it<<endl;
        }
    }
    return 0;
}