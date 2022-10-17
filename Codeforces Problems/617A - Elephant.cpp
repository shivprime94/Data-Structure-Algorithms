//Author: Akash Gautam (@geekblower)
//Date: 28-06-2022
#include <iostream>
#include <string>
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
const int MOD = 1e9+7;

void solve() {
    create(x)
    int step=0;
    
    if(x>=5) {
        step += x/5;
        x %= 5;
    }
    
    if(x>=4) {
        step += x/4;
        x %= 4;
    }
    
    if(x>=3) {
        step += x/3;
        x %= 3;
    }
    
    if(x>=2) {
        step += x/2;
        x %= 2;
    }
    
    step += x;
    
    display(step)
}

int32_t main() {
    GEEKBLOWER
    SOLUTION
}
