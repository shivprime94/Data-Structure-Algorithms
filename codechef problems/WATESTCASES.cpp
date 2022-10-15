// Problem Link : https://www.codechef.com/START52D/problems/WATESTCASES

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pp pop_back
#define Vec vector<long long int>
const long long int MOD = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0;i < n;i++){
        int x;
        cin>>x;
        v.pb(x);
    }
    string s;
    cin>>s;
    for(int i = 0;i < n;i++){
        if(s.at(i) == '1'){
            v[i]=0;
        }
    }
    sort(v.begin(),v.end());
    int j;
    for(j = 0;j < n;j++){
        if(v[j] != 0){
            break;
        }
    }
    cout<<v[j]<<"\n";
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