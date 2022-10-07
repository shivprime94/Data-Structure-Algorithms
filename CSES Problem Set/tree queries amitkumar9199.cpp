#include<bits/stdc++.h>
using namespace std;
 
void distance_queries() {
	int n,q;
	cin>>n>>q;
	vector<vector<int>> e(n);
	for(int i=0;i<n-1;i++) {
		int a,b;
		cin>>a>>b;
		e[a-1].push_back(b-1);
		e[b-1].push_back(a-1);
	}
 
	int _log=20;
	
	vector<vector<int>> up(n,vector<int>(_log+1,0));
	vector<int> depth(n,0);
	for(int i=0;i<_log;i++) {
		up[0][i]=0;
	}
 
	auto dfs=[&](int cur,int par,auto &&dfs)->void{
		up[cur][0]=par;
		for(int i=1;i<_log+1;i++) {
			up[cur][i]=up[up[cur][i-1]][i-1];
		}
		for(auto node:e[cur]) {
			if(node!=par) {
				depth[node]=depth[cur]+1;
				dfs(node,cur,dfs);
			}
		}
	};
	dfs(0,0,dfs);
 
	auto getKthanc=[&](int node,int k)->int{
		if(k>depth[node]) return -1;
		int bit=0;
		while(k) {
			if(k%2) node=up[node][bit];
			k/=2; bit++;
		}
		return node;
	};
 
	auto getDist=[&](int u,int v)->int{
		if(depth[u]>depth[v]) {
			swap(u,v);
		}
		int res=depth[v]-depth[u];
		v=getKthanc(v,depth[v]-depth[u]);
		if(v==u) return res;
		int add=1<<(_log+1);
		for(int bit=_log;bit>=0;bit--) {
			if(up[u][bit]!=up[v][bit]) {
				u=up[u][bit];
				v=up[v][bit];
				res+=add;
			}
			add/=2;
		}
		return res+2;
	};
 
	while(q--) {
		int u,v;
		cin>>u>>v;
		u--;v--;
		cout<<getDist(u,v)<<"\n";
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	distance_queries();
}
