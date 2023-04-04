// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int solve2(vector<int> &cost,int n,vector<int> &dp){
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<=n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return solve2(cost,n,dp);
    }
};