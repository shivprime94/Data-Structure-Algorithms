//Author: Akash Gautam (@geekblower)
//Date: 14-07-2022
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
#define print(a) for(auto i : a){cout<<i;};
#define vector(a,n) VI a;loop(i,0,n,1){int x;cin>>x;a.PB(x);}
inline int GCD(int a,int b){return !b?a:GCD(b,a%b);}
const int MOD = 1000000007;

void solve() {
    create(n)
    create(m)
    
    vector<vector<char>> snake;
    bool right = true;
    bool left = false;
    
    start_loop {
        vector<char> temp;
        
        loop(j, 0, m, 1) {
            if(i%2==0)
                temp.PB ('#');
            else
                temp.PB ('.');
        }
        
        if(right && i&1) {
            temp[m-1] = '#';
            right = false;
            left = true;
        } else if(left && i&1) {
            temp[0] = '#';
            left = false;
            right = true;
        }
        
        snake.PB (temp);
    }
    
    start_loop {
        print(snake[i])
        cout<<endl;
    }
}

int32_t main() {
    GEEKBLOWER
    SOLUTION
}
