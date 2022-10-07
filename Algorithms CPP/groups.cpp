/*
https://codeforces.com/contest/1598/problem/B
*/
#include <bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		// std::vector<int> v;
		// vector<vector<int>> v;
		int v[n][5];
		for(int i=0;i<n;i++){
			for(int j=0;j<5;j++){
				cin>>v[i][j];
			}
		}
		int flag=0;
		for(int i=0;i<5;i++){
			for(int j=i+1;j<5;j++){
				int cnta=0,cntb=0,cntab=0,cnt=0;
				for(int k=0;k<n;k++){
					if(v[k][i]==1 && v[k][j]==0)
						cnta++;	
					if(v[k][j]==1 && v[k][i]==0)
						cntb++;
					if(v[k][i]==0 && v[k][j]==0){
						cnt++;break;
					}
				}
				if(cnt!=0)
					continue;
				else if(cnta>n/2 || cntb>n/2)
					continue;
				else{
					flag=1;break;
				}
			}
		}
		if(flag==0)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
}
