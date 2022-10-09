//Author: Akash Gautam (@geekblower)
//Date: 09-10-2022
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define GEEKBLOWER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define TEST_CASES create(t);while(t--)
#define SOLUTION solve(); return 0;
#define display(n) cout<<n<<endl;
#define VI vector<int>
#define PB push_back
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define loop(i,a,b,c) for(int i=a;i<b;i+=c)
#define revloop(i,a,b,c) for(int i=a;i>=b;i-=c)
#define start_loop loop(i,0,n,1)
#define start_revloop revloop(i,n,0,1)
#define create(n) int n;cin>>n;
#define def(a,n) int a[n];start_loop cin>>a[i];
#define print(a) for(auto i : a){cout<<i<<" ";}cout<<endl;
#define vector(a,n) VI a;loop(i,0,n,1){int x;cin>>x;a.PB(x);}
inline int GCD(int a,int b){return !b?a:GCD(b,a%b);}
const int MOD = 998244353;

int calcPower(int b, int n) {
    int s = 1;
    
    while(n) {
        if(n&1)
            s = s*b%MOD;
        b = b*b%MOD;
        n /= 2;
    }
    
    return s;
}

int count(int i, int j) {
   return ((i/(1<<(j+1)))<<j) + (max(0ll,i%(1<<(j+1)) - (1<<j)+1));
}

void solve(){
    create(n)
    create(m)
    
    int s = 0;
    
    loop(i, 0, 31, 1) {
        s = (s+(calcPower(count(m,i),n)<<i) % MOD) % MOD;
    }
    
    display(s)
}

int32_t main() {
    GEEKBLOWER
    TEST_CASES
    SOLUTION
}
