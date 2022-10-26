/*
Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.


Example 1:

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin

Example 2:

Input: V = 11, M = 4,coins[] = {9, 6, 5, 1} 
Output: 2 
Explanation: Use one 6 cent coin
and one 5 cent coin
*/

class Solution{	
   public:
	int rec(int coins[], int M, int V, int i, vector<vector<int>> &dp)
	{
	    if(V==0)
	        return 0;
	    if(i==M)
	        return -1;
	    
	    if(dp[i][V]!=-1)
	        return dp[i][V];
	    
	    int res=INT_MAX;    
	    //including coins[i]
	    if(V>=coins[i]){
	        int a=rec(coins, M, V-coins[i], i+1, dp);
	        int b=rec(coins, M, V-coins[i], i, dp);
	        if(a!=-1)
    	        res=min(res, 1+a);
    	    if(b!=-1)
    	        res=min(res, 1+b);
	    }
	    
	    //excluding coins[i]
	    int c=rec(coins, M, V, i+1, dp);
	    if(c!=-1)
    	   res=min(res, c);
    	   
    	res= (res==INT_MAX?-1:res);
	    
	    dp[i][V]=res;
	    return res;
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M+1,vector<int>(V+1,-1));
	    return rec(coins, M, V, 0, dp);
	} 

};