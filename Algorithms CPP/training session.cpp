/*
https://codeforces.com/contest/1598/problem/D
*/
#include <bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		
		vector<vector<int>> v(n);
		
		map<int, int> x;
		map<int, int> y;
		int temp;

		for(int i=0;i<n;i++){
			cin>>temp;
			v[i].push_back(temp);x[temp]++;
			cin>>temp;
			v[i].push_back(temp);y[temp]++;
		}
		long long int minus=0;
		for(int i=0;i<n;i++){
			minus+=(x[v[i][0]]-1)*1LL*(y[v[i][1]]-1);
		}
		long long int ans=1LL*n*(n-1)*(n-2)/6;
		ans-=minus;
		cout<<ans<<endl;
	}
	return 0;
}
