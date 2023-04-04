// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
bool solve(vector<vector<char>>& board,int p,int q){
    set<char>s;
    for(int i=p;i<p+3;i++){
        for(int j=q;j<q+3;j++){
            // cout<<i<<' '<<j<<endl;
                if(s.find(board[i][j])!=s.end()){
                    // cout<<board[i][j]<<' '<<endl;
                    return false;
                }
                else if(board[i][j]!='.') s.insert(board[i][j]);
        }
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char>s;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(s.find(board[i][j])!=s.end()){
                    return false;
                }
                else if(board[i][j]!='.') s.insert(board[i][j]);
            }
            s.clear();
        }
        s.clear();
        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                if(s.find(board[i][j])!=s.end()){
                    return false;
                }
                else if(board[i][j]!='.') s.insert(board[i][j]);
            }
            s.clear();
        }
        bool f= true;
        int i=0;
        while(i<8){
            int j=0;
            while(j<8){
                f=f && solve(board,i,j);
                j=j+3;
            }
            i=i+3;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<board[i][j]<<' ';
            }
            cout<<endl;
        }
        return f;
    }
};