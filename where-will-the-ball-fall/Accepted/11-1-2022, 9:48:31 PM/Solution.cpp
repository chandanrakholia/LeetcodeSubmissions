// https://leetcode.com/problems/where-will-the-ball-fall

class Solution {
public:
    int findballbycolumn(int row,int col,vector<vector<int>>& grid){
        if(row==grid.size()) return col;
        int nextcol=col+grid[row][col];
        if(nextcol<0|| nextcol>grid[0].size()-1 || grid[row][col]!=grid[row][nextcol]) return -1;
        return findballbycolumn(row+1,nextcol,grid);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>v(grid[0].size(),0);
        for(int i=0;i<grid[0].size();i++){
            v[i]=findballbycolumn(0,i,grid);
        }
        return v;
    }
};