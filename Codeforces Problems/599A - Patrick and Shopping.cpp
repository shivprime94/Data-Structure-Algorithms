//Author: Akash Gautam (@geekblower)
//Date: 24-08-2022
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
const int MOD = 1000000007;

void solve() {
    create(d1)
    create(d2)
    create(d3)
    
    int p1 = d1+d1+d2+d2;
    int p2 = d1+d3+d2;
    int p3 = d1+d3+d3+d1;
    int p4 = d2+d3+d3+d2;
    
    if(p1<p2 && p1<p3 && p1<p4)
        display(p1)
    else if(p2<p3 && p2<p4)
        display(p2)
    else if(p3<p4)
        display(p3)
    else
        display(p4)
}

int32_t main() {
    GEEKBLOWER
    SOLUTION
}
