/*
https://codeforces.com/contest/1586/problem/B
*/
#include <bits/stdc++.h>
#include<vector>
using namespace std;


vector<vector<int>> adj;
 
// function to initialise
// the adjacency matrix
void init(int n)
{
    for(int i=1;i<=n;i++)
        adj[i][i]=1;
}
 
// Function to add edge between nodes
void addEdge(int a,int b)
{
    adj[a][b]=1;
    adj[b][a]=1;
}
 
// Function to compute the path
void computePaths(int n)
{
    // Use Floyd Warshall algorithm
    // to detect if a path exists
    for(int k = 1; k <= n; k++)
    {
        // Try every vertex as an
        // intermediate vertex
        // to check if a path exists
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                adj[i][j] = adj[i][j] | (adj[i][k] && adj[k][j]);
    }
}
 
bool isReachable(int s, int d)
{
    if (adj[s][d] == 1)
        return true;
    else
        return false;
}
 

int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n,m;scanf("%d%d",&n,&m);
        int output[n-1][2];int k=0;
		int v[m][3];
        adj = vector<vector<int>>(n+1,vector<int>(n+1,0));init(n);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&v[i][0],&v[i][1],&v[i][2]);
            // if(no_path(v[i][0],v[i][1],v[i][2]==true){
            //     output[k][0]=    
            // }
            output[k][0]=v[i][0];
            output[k][1]=v[i][2];k++;
            addEdge(v[i][0],v[i][2]);
        }
        computePaths(n);
 
        // int u = 4, v = 3;
        // if(isReachable(u,v))
        //     cout << "Yes\n";
        // else
        //     cout << "No\n";
        // return 0;
        for(int i=2;i<=n;i++){
            if(isReachable(1,i)==false){
                addEdge(1,i);computePaths(n);
                output[k][0]=1;
                output[k][1]=i;k++;
            }
        }
        for(int i=0;i<k;i++){
            cout<<output[i][0]<<" "<<output[i][1]<<endl;
        }
           
    }
	return 0;
}
