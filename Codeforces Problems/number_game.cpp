#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define LP1(i,a,b) for(int i=a;i<b;i++)
#define LP2(i,a,b) for(int i=a;i>=b;i--)
#define digits(n) ((int)log10l(abs(n))+1)
#define mod(n) ((int)(n)%1000000007)
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef multiset<int> msi;
typedef unordered_set<int> usi;
typedef map<int,int> mi;
typedef unordered_map<int,int> umi;
typedef multimap<int,int> mmi;
#define MTS
 
bool check(int k,vi v){
    int cnt=0;
    while(k){
        if(v[cnt]<=k){
        auto it=upper_bound(v.begin(),v.end(),k);
        *(--it)=k;
        k--;
        cnt++;
        }
        else return false;
    }
    return true;
    
}
 
int bins(int s,int f,vi v){
    int ans=0;
    while(s<=f){
        int mid=(s+f)/2;
        if(check(mid,v)){
            ans=mid;
            s=mid+1;
        }
        else f=mid-1;
    }
    return ans;
}
 
void solve(){
    int n;cin>>n;
    vi v(n);
    LP1(i,0,n) cin>>v[i];
    sort(v.begin(),v.end());
    cout<<bins(0,n,v)<<endl;
    
}
 
 
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
#ifdef MTS
    int t;
    cin>>t;
    while(t--)
#endif
    solve();
    return 0;
}
