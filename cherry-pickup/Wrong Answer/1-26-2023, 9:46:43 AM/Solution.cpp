// https://leetcode.com/problems/cherry-pickup

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int> > dp(n, vector<int> (n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==-1){
                    dp[i][j]=-1;
                }
                else if(i==0 and j==0){
                    dp[i][j]=grid[i][j];
                }
                else if(i==0 and dp[i][j-1]!=-1){
                    dp[i][j]=grid[i][j]+dp[i][j-1];
                }
                else if(i==0){
                    dp[i][j]=-1;
                }
                else if(j==0 and dp[i-1][j]!=-1){
                    dp[i][j]=grid[i][j]+dp[i-1][j];
                }
                else if(j==0){
                    dp[i][j]=-1;
                }
                else{
                    if(dp[i][j-1]==-1 and dp[i-1][j]==-1){
                        dp[i][j]=-1;
                    }
                    else if(dp[i-1][j]==-1){
                        dp[i][j]=dp[i][j-1]+grid[i][j];
                    }
                    else if(dp[i][j-1]==-1){
                        dp[i][j]=dp[i-1][j]+grid[i][j];
                    }
                    else{
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    }
                }
            }
        }
        if(dp[n-1][n-1]<=0) return 0;
        else{
            return dp[n-1][n-1];
        }
    }
};