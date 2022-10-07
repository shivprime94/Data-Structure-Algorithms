/*
Leetcode - 70 Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];//cause of the base cases we take n+1
        //bottom up approach
        dp[0]=1; //ways to climb 0steps is 1 i.e no climbing
        dp[1]=1;//ways to climb 1 steps is 1 i.e by taking 1 step
        //for the rest of the stairs
        for(int i=2; i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
            //current step will be the sum of previous 2 steps
            //dp[2]=dp[1]+dp[0]
        }
        return dp[n];
    }
};
