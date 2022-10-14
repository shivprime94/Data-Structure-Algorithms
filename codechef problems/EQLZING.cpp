// Problem Link: https://www.codechef.com/LTIME111D/problems/EQLZING

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pp pop_back
#define Vec vector<long long int>
const long long int MOD = 1e9+7;

void solve(){
    int x,y;
    cin>>x>>y;
    if(x == y){
        cout<<"Yes"<<"\n";
    }else{
        int def = abs(x - y);
        if((def & 1) != 0){
            cout<<"No"<<"\n";
        }else{
            cout<<"Yes"<<"\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}