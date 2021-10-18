#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    // making and initializing dp array
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {
 
            if (wt[i - 1] <= w)
                // finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W]; // returning the maximum value of knapsack
}
int main()
{
    int n,W;
    cin>>n;
    vector<int> val,wt;
    int v,w;
    for(int i=0;i<n;i++){
        cin>>v>>w;
        val.push_back(v);
        wt.push_back(w);
    }
    cin>>W;
    cout << knapSack(W, wt, val, n);
    return 0;
}
