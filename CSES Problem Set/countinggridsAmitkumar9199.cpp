#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;

ll modp(ll base,ll exp) {
    ll res=1;
    while(exp) {
        if(exp%2) {
            res=(res*base)%mod;
        }
        base=(base*base)%mod;
        exp/=2;
    }
    return res;
}
 
ll _0(ll n) {
    ll p=n*n;
    return modp(2ll, p);
}
 
ll _90(ll n) {
    ll r=n/2;
    ll p;
    if(n%2) 
        p=(r*(r+1)+1);
    else
        p=(r*r);
    return modp(2,p);
}
 
ll _180(ll n) {
    ll p=(n*n+1)/2;
    return modp(2,p);
}
 
void counting_grids() {
    ll n;
    cin >> n;
    ll ans=0;
    
    ans = (_0(n)+_180(n))%mod;
    ans = (ans+(_90(n)+_90(n))%mod)%mod;
    ans = (ans * modp(4,mod-2))%mod;
    cout << ans << "\n";
}
 
int32_t main() {
    counting_grids();
}
