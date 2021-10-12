/*

question link--https://codeforces.com/contest/1598/problem/C

*/


#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		// std::vector<int> v;
		vector<int> v(n);
		map<int, int> count;
		for(auto &x:v){
			scanf("%d",&x);
			count[x]++;
		}
		long long int sum=accumulate(v.begin(),v.end(),0LL);
		if((2*sum)%n==0){
			long long int need = 2*sum/n;
			long long ans=0LL;
			for(int i=0;i<n;i++){
				int v1=v[i];
				int v2=need-v1;
				if(count.count(v2))
					ans+=count[v2];
				if(v1==v2)
					ans-=1;
			}
			cout<<ans/2<<endl;
		}
		else{
			puts("0");//breaks the line automatically
			continue;
		}
	}
}
