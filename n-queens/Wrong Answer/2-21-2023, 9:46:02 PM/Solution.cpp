// https://leetcode.com/problems/n-queens

class Solution {
private:
    bool isSafe(int row, int col,vector<string>&board, int n){
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q') return false;
            if(row-1>=0 and col+1<n and board[row-1][col+1]=='Q') return false;
            if(row-1>=0 and col-1>=0 and board[row-1][col-1]=='Q') return false;
        }
        return true;
    }
    void solve(int row, vector<vector<string>>&sols,vector<string>&board, int n){
        if(row==n){
            sols.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(row+1, sols,board, n);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n ,string(n,'.'));
        vector<vector<string>>sols;
        solve(0,sols,board,n);
        return sols;
    }
};