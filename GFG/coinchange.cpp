#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   int findway(int index,int target,int coins[],vector<int> dp)
   {
      //base case
      
      if(index == 0){
          if(target % coins[0] == 0){
              return 1;
          }
          
          else{
            return 0;
          }    
      }
      
      if(target == 0){
          return 1;
      }
      
      if(dp[index] != -1) return dp[index];
      
      int nottake = findway(index-1,target,coins,dp);
      
      int take = 0;
      if(target >= coins[index]){
          take = findway(index,target-coins[index],coins,dp);
      }
      
      return dp[index] = take + nottake;
   }
  

    long long int count(int coins[], int N, int sum) {
      vector<int> dp(N,-1);
      //calling function of this class
      long long int ans = findway(N-1,sum,coins,dp);
      return ans;
    }
};



//main function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}