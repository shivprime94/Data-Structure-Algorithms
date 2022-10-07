#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define MOD (int)(1e9+7)
 
void solve(){
    int n;cin>>n;
    int sum=1,val=2,stp=1,sum_taken=1;
    vector<int> sarray={0,0,0,0,0,1};
    while(val<=n){
        stp=0;
        if(val<=6)stp=1;
        (stp+=sum)%=MOD;
        sum=stp;
        for(int i=0;i<5;i++){
            sarray[i]=sarray[i+1];
            sum+=sarray[i];
        }
        sarray[5]=stp;
        val++;
    }
    cout<<stp<<endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //int _t;cin>>_t;while(_t--)
        solve();
}
