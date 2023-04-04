// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int dp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[i][j]=matrix[i][j];
                }
                else{
                    if(j==0){
                        dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+matrix[i][j];
                    }
                    else if(j==n-1){
                        dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+matrix[i][j];
                    }
                    else{
                        dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i-1][j+1])+matrix[i][j];
                    }
                }

            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini, dp[n-1][i]);
        }
        return mini;
    }
};