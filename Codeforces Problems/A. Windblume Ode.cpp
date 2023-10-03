/*
https://codeforces.com/contest/1586/problem/A
*/
#include <bits/stdc++.h>
#include<vector>
using namespace std;


bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);	
		int sum=0;
		vector<int> v(n);
        for(int i=0;i<n;i++){
            scanf("%d",&v[i]);
        	sum+=v[i];	
        }
        int count = n;int index=-1;
        if(isPrime(sum)==true){
        	for(int i=0;i<n;i++){
        		if(v[i]%2==1){
        			index=i;
        			count--;
        			sum-=v[i];
        			break;
        		}
        	}
        }
        cout<<count<<endl;
		for(int i=0;i<n;i++){
			if(i==index)	continue;
			cout<<i+1<<" ";
		}
		cout<<endl;
    }
	return 0;
}