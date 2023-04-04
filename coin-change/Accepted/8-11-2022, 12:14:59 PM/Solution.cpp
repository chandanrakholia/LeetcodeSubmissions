// https://leetcode.com/problems/coin-change

class Solution {
public:
    int solve(vector<int> &num,int n,int x){
    int dp[n+1][x+1];
    for(int i=0;i<=x;i++){
        dp[0][i]=INT_MAX-1;
    }
    for(int j=1;j<=n;j++){
        dp[j][0]=0;
    }
    for(int j=1;j<=x;j++){
        if(j%num[0]==0){
            dp[1][j]=j/num[0];
        }
        else{
            dp[1][j]=INT_MAX-1;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(num[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-num[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    if(dp[n][x]==INT_MAX-1) return -1;
    else
    return dp[n][x];
}
    int coinChange(vector<int>& coins, int amount) {
        return solve(coins,coins.size(),amount);
    }
};