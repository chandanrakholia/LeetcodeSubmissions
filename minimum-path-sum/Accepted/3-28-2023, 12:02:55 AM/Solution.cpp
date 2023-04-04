// https://leetcode.com/problems/minimum-path-sum

class Solution {
private:
    void print(vector<int>arr){
        for(auto i: arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int solve(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<int>prev(m),curr(m);
        //base case
        prev[0]=grid[0][0];
        for(int i=1;i<m;i++){
            prev[i]=prev[i-1]+grid[0][i];
        }
        print(prev);
        for(int i=1;i<n;i++){
            curr[0]=prev[0]+grid[i][0];
            for(int j=1;j<m;j++){
                curr[j]=grid[i][j]+min(prev[j], curr[j-1]);
            }
            prev=curr;
            print(curr);
        }
        return prev[m-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        return solve(grid);
    }
};