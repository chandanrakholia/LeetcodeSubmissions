// https://leetcode.com/problems/coin-change-ii

class Solution {
public:
    int solve(vector<int> &num,int n,int x){
    int dp[n+1][x+1];
    for(int i=0;i<=x;i++){
        dp[0][i]=0;
    }
    for(int j=1;j<=n;j++){
        dp[j][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(num[i-1]<=j){
                dp[i][j]=dp[i][j-num[i-1]]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    // if(dp[n][x]==INT_MAX-1) return -1;
    // else
    return dp[n][x];
}
    int change(int amount, vector<int>& coins) {
        return solve(coins,coins.size(),amount);
    }
};