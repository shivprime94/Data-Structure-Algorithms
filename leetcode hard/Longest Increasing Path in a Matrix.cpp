class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int dp[210][210];
    int vis[210][210];
    int n,m;
    bool check(int i,int j){
        if(i>=0 && i<n && j>=0 && j<m) return true;
        else return false;
    }
    void dfs(int i,int j,vector<vector<int>>& matrix){
        vis[i][j] = 1;
        dp[i][j] = 1;
       
        for(int k=0;k<4;k++){
            if(check(i+dx[k],j+dy[k])  && matrix[i+dx[k]][j+dy[k]]>matrix[i][j]){
               
                if(vis[i+dx[k]][j+dy[k]]==0) dfs(i+dx[k],j+dy[k],matrix);
                dp[i][j] = max(dp[i][j],dp[i+dx[k]][j+dy[k]]+1);
            }
        }
        
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(vis,0,sizeof(vis));
         n = matrix.size(); m = matrix[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(vis[i][j]==0) {
                    dfs(i,j,matrix);
                    
                }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                    ans = max(ans,dp[i][j]);
        }
        return ans;
    }
};
