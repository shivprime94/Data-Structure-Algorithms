//Author: Akash Gautam (@geekblower)
//Date: 08-08-2022
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
    create(a)
    create(b)
    create(c)
    
    if(a==b && b==c) {
        display("1 1 1")
        return;
    }
    
    int maximum = (a>b && a>c) ? a : (b>c ? b : c);
    
    int temp1 = (a==maximum) ? ((a==b || a==c) ? 1 : 0) : maximum-a+1;
    int temp2 = (b==maximum) ? ((b==a || b==c) ? 1 : 0) : maximum-b+1;
    int temp3 = (c==maximum) ? ((c==b || c==a) ? 1 : 0) : maximum-c+1;
    
    display(temp1<<" "<<temp2<<" "<<temp3)
}

int32_t main() {
    GEEKBLOWER
    TEST_CASES
    SOLUTION
}
