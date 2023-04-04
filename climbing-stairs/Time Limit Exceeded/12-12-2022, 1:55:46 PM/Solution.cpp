// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        int dp[46]={0};
        if(n==1) return dp[1]=1;
        if(n==2) return dp[2]=2;
        if(dp[n]!=0) return dp[n];
        return dp[n]=climbStairs(n-1)+climbStairs(n-2);
    }
};