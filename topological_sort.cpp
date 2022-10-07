
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

    
vector<int> topoSort(int V, vector<int> adj[]) {
	    
	    vector<int> ans;
	    vector<int> indegree(V);
	    
	    for(int i=0 ; i<V ; i++){
	        indegree[i] = 0;
	    }
	    
	    for(int i=0 ; i<V ; i++){
	        for(int j=0 ; j<adj[i].size() ; j++){
	            indegree[adj[i][j]]++;
	        }
	    }

	    queue<int> q;

	    
	    for(int i=0 ; i<V ; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	            ans.push_back(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int front  = q.front();
	        q.pop();
	        for(int i=0 ; i<adj[front].size() ; i++){
	            indegree[adj[front][i]]--;
	            if(indegree[adj[front][i]] == 0){
	                ans.push_back(adj[front][i]);
	                q.push(adj[front][i]);
	            }
	        }
	    }
	    

	    
	    return ans;
	    
	}

    int main(){
    
        int V,E;
        cin>>V>>E;
        vector<int>* adj = new vector<int>[V];
        for(int i=0 ; i<E ; i++){
            int src , dst;
            cin>>src>>dst;
            adj[src].push_back(dst);
        }

        
        vector<int> ans = topoSort(V, adj);
        for(int i=0 ; i<ans.size() ; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }


// 5 5
// 1 2
// 2 3
// 3 4
// 4 5
// 3 5

// 5 5
// 0 1
// 1 2
// 2 3
// 3 4
// 2 4