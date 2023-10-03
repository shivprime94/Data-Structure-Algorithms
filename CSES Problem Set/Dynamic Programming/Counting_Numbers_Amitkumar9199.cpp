#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
using ii = pair<ll,ll>;
 
const ll mod = 1e9+7;
 
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define len(x) ((ll)((x).size()))
#define rep(i,x) for(ll i=0;i<(x);i++)
#define all(x) (x).begin(),(x).end()
 
struct segtree_iterative{
    int n;vector<ll> t;
    segtree_iterative(vector<ll> arr_){
        n=(int)arr_.size();
        t.resize(2*n+5);
        for(int i=0;i<n;i++)t[i+n]=arr_[i];
        build();
    }
    void build(){
        for(int i=n-1;i>=1;--i)
            t[i] = t[i<<1] + t[i<<1|1];
    }
    void update(int pos,ll val){
        for(t[pos+=n] = val; pos>1; pos>>=1)
            t[pos>>1] = t[pos] + t[pos^1];
    }
    ll query(int l,int r){
        ll res=0;
        // range [l,r]
        for(l+=n, r+=n; l<=r; l>>1 , r>>1){
            if(l&1)     res+=t[l++];
            if(!(r&1))  res+=t[r--];
        }
        // // range [l,r)
        // for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        //     if (l&1) res += t[l++];
        //     if (r&1) res += t[--r];
        // }
        return res;
    }
    void range_update(int l,int r,ll val){
        for(l+=n, r+=n; l<=r; l>>1, r>>1){
            if(l&1)     t[l++] += val;
            if((r&1))   t[r--] += val;
        }
        // for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        //     if (l&1) t[l++] += value;
        //     if (r&1) t[--r] += value;
        // }
    }
    ll point_query(int p){
        ll res=0;
        for(p+=n; p>0; p>>=1) res+=t[p];
        return res;
    }
    void push() {
        // if at some point after modifications we need to inspect all the elements in the array, we can push all the modifications to the leaves using the following code. After that we can just traverse elements starting with index n. This way we reduce the complexity from O(nlog(n)) to O(n) similarly to using build instead of n modifications.
        for (int i = 1; i < n; ++i) {
            t[i<<1] += t[i];
            t[i<<1|1] += t[i];
            t[i] = 0;
        }
    }
    // just pass the 0-index vector arr for intialization
    // build is carried out automatically
    // update(idx,val) -> idx is 0-indexed position in vector arr 
    // query(l,r) -> l,r is 0-based index in vector arr 
}typedef(segtree_iterative);
string a,b;int n;
ll dp[20][2][2][10][2];
ll rec(int idx, bool lo,bool hi,int prev=0,bool f=0){
    if(idx>=n){
        return 1;
    }
    if(~dp[idx][lo][hi][prev][f])
        return dp[idx][lo][hi][prev][f];
    int low=0,high=9;
    if(lo)low=a[idx]-'0';
    if(hi)high=b[idx]-'0';
    ll ans=0;
    for(int i=low;i<=high;i++){
        if(f && i==prev)continue;
        bool nlo=lo,nhi=hi,nf=f;
        if(i!=a[idx]-'0')nlo=0;
        if(i!=b[idx]-'0')nhi=0;
        if(i)nf=1;
        ans+=rec(idx+1,nlo,nhi,i,nf);
    }
    return dp[idx][lo][hi][prev][f]=ans;
}
void solve(){
    memset(dp,-1,sizeof(dp));
    ll x,y;
    cin>>x>>y;
    while(x>0){a+=((x%10)+'0');x/=10;}
    while(y>0){b+=((y%10)+'0');y/=10;}
    while(len(a)<len(b))a+='0';
    while(len(b)<len(a))b+='0';
    reverse(all(a));
    reverse(all(b));
    n=len(a);
    // cout<<a<<" "<<b<<endl;
    cout<<rec(0,1,1)<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
