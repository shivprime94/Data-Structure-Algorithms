#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int max(int a,int b){
	if(a>=b)
		return a;
	return b;
}

int main(){
	char s[3001],t[3001];scanf("%s%s",s,t);
	int n=strlen(s);int m=strlen(t);
	int dp[n+1][m+1];
	for(int i=0;i<n+1;i++)
		dp[i][0]=0;
	for(int i=1;i<m+1;i++)
		dp[0][i]=0;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			if(s[i-1]==t[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
		}
	}
	char output[3001];
	int i=n;int j=m;output[dp[i][j]]='\0';
	while(i>=1 && j>=1){
		while(dp[i][j]==dp[i][j-1] && j>=1)
			j--;
		
		while(dp[i][j]==dp[i-1][j] && i>=1)
			i--;
		if(i==0)
			break;
		
		output[dp[i][j]-1]=s[i-1];i--;j--;
	}
	cout<<output<<endl;
	return 0;
	//cout<<s<<endl<<t<<endl;
}
