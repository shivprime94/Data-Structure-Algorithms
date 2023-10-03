#include <bits/stdc++.h>
using namespace std;
#define int long long
double dp[1<<19];
int done[1<<19];
double p[20][20];
int n;
double rec(int s){
    if(s==(1<<n)-1) return 1;
    if(done[s]) return dp[s];
    if(s==0){
        int s1;
        for(int i=1;i<=n;i++){
            s1=s|(1<<(i-1));
            dp[s|(1<<(i-1))]=(double)0;
            for(int j=1;j<=n;j++){
                if(i!=j)
                dp[s|(1<<(i-1))]+=p[i][j] * rec(s1|(1<<(j-1)));
            }
        }
        return (double) 0;
    }
    else{
       int cnt=0;
        for(int i=1;i<=n;i++){
            if(s&(1<<(i-1))) cnt++;
        }
        dp[s]=0;
         for(int i=1;i<=n;i++){
            if(!(s&(1<<(i-1)))){
                for(int j=1;j<=n;j++){
                    if(s&(1<<(j-1))){
                        dp[s]+=p[j][i]*rec(s|(1<<(i-1)));
                    }
                }
            }
        }
        dp[s]/=(double)cnt*(cnt+1);
        dp[s]*=(double)2;
        done[s]=1;
    
    return dp[s];
    }
}
 
 
 
 
int32_t main()
{
    cin>>n;
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) 
    cin>>p[i][j];
    if(n==1) cout<<1.000000;
    else {
    double ans=rec(0);
    for(int i=1;i<=n;i++)
    cout<<fixed<<setprecision(6)<<dp[1<<(i-1)]<<" ";
    }
 
    
    
 
    return 0;
}
