#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int N = 1e6+7;
 
int dp[N] = {};
 
int32_t main()
{
    int n; cin >> n;
    int k = 7;
    dp[0] = 1;
    for(int i = 0; i<n+1; i++){
        for(int j =1; j<min(i+1,k); j++){
               dp[i] += dp[i-j];
        }
         dp[i] = dp[i]%mod;
    }
    cout << dp[n]%mod << "\n";
	return 0;
}
