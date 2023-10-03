#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mod 1000000007
#define pb push_back
//int dp[200005][2];
//int h[200005];
//vector<vector<int>> t(200005);
 
void solve(){
    int a,b,c,d;cin>>a>>b>>c>>d;
   int y,pr=a*b;
    for(int i=a+1;i<=c;i++){
      
                int e=__gcd(pr,i);
                int f=pr/e;
                int c1=(b+1)/f,c2=(d)/f;
                if((c2-c1)>=1){
            cout<<i<<" "<<(c1+1)*f<<endl;
            return;
            }
             if((b+1)%f==0){
            cout<<i<<" "<<(c1)*f<<endl;
            return;
            }
             if(d%f==0){
            cout<<i<<" "<<(c2)*f<<endl;
            return;
            }
                
            
            
            
        }
    
    
    for(int i=b+1;i<=d;i++){
        int e=__gcd(pr,i);
                int f=pr/e;
                int c1=(a+1)/f,c2=(c)/f;
                if((c2-c1)>=1){
            cout<<i<<" "<<(c1+1)*f<<endl;
            return;
            }
             if((a+1)%f==0){
            cout<<i<<" "<<(c1)*f<<endl;
            return;
            }
             if(c%f==0){
            cout<<i<<" "<<(c2)*f<<endl;
            return;
            }
                
            
    }
    
    
    cout<<-1<<" "<<-1<<endl;
    return;
}
 
 
signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
