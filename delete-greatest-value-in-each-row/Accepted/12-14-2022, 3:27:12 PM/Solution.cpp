// https://leetcode.com/problems/delete-greatest-value-in-each-row

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            sort(grid[i].begin(),grid[i].end(),greater<int>());
        }
        int ans=0;
        for(int j=0;j<m;j++){
            int ma=INT_MIN;
            for(int i=0;i<n;i++){
                if(grid[i][j]>ma){
                    ma=grid[i][j];
                }
            }
            ans+=ma;
        }
        return ans;
    }
};