//Author: Akash Gautam (@geekblower)
//Date: 03-07-2022
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
const int MOD = 1000000007;

void solve() {
    create(n)
    create(m)
    create(k)
    
    int arr[101] = {0};
    
    start_loop {
        create(val)
        arr[val]++;
    }
    
    int bef=0;
    
    loop(i, 0, k, 1) {
        if(arr[i]==0) {
            display("NO")
            return;
        }
        bef++;
    }
    
    int after = n - bef - arr[k];
    
    if(m>=k && m<=(n-arr[k]))
        display("YES")
    else
        display("NO")
}

int32_t main() {
    GEEKBLOWER
    TEST_CASES
    SOLUTION
}
