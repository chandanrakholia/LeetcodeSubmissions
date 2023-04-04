// https://leetcode.com/problems/minimum-falling-path-sum-ii

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
                    int mini=INT_MAX;
                    for(int k=0;k<n;k++){
                        if(k!=j){
                            mini=min(mini,dp[i-1][k]);
                        }
                    }
                    dp[i][j]=mini+matrix[i][j];
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