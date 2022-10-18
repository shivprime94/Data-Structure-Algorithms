//Author: Akash Gautam (@geekblower)
//Date: 19-08-2022
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
    create(n)
    string num1;
    string num2;
    cin>>num1>>num2;
    
    int totalMoves = 0;
    
    start_loop {
        int last = num1[i] - '0';
        int first = num2[i] - '0';
        
        int a = (last>first) ? last : first;
        int b = (last>first) ? first : last;
        
        if((a-b) < (10-a+b))
            totalMoves += (a-b);
        else
            totalMoves += (10-a+b);
    }
    
    display(totalMoves)
}

int32_t main() {
    GEEKBLOWER
    SOLUTION
}
