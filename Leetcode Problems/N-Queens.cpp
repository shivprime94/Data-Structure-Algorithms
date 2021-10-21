class Solution {
public:
    
    char board[11][11];
    vector<vector<string>> v;
    
    bool isPossible(int n, int row, int i){
        // Check up
        for(int k=row-1;k>=0;k--){
            if(board[k][i] == 'Q'){
                return false;
            }            
        }
        // Up Left Diagonal
        for(int k=row-1,t = i-1;k>=0 && t>=0;k--,t--){
            if(board[k][t] == 'Q'){
                return false;
            }            
        }
        
        // Up Right Diagonal
        for(int k=row-1,t = i+1;k>=0 && t<n;k--,t++){
            if(board[k][t] == 'Q'){
                return false;
            }            
        }
        return true;
    }
    
    void NQueen(int n, int curr_row){
        vector<string> temp;
        if(curr_row == n){
            for(int i=0;i<n;i++){
                string str;
                for(int j=0;j<n;j++){
                    str+=board[i][j];
                }
                temp.push_back(str);
            }
            v.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isPossible(n,curr_row,i)){
                board[curr_row][i] = 'Q';
                NQueen(n,curr_row+1);
                board[curr_row][i] = '.';
            }
        }
    }
    
    void NQueens(int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j] = '.';
            }
        }
        NQueen(n,0);
    }
    vector<vector<string>> solveNQueens(int n) {
        NQueens(n);
        return v;    
    }
};
