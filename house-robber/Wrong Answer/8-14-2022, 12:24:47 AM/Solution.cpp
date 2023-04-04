// https://leetcode.com/problems/house-robber

class Solution {
public:
    int solve(vector<int>&nums,int n,vector<int>&dp){
    if(n==0) return dp[0]=nums[0];
    if(n==1) return dp[1]=nums[1];
    else if(dp[n]!=-1) return dp[n];
    return dp[n]=max(solve(nums,n-1,dp),nums[n]+solve(nums,n-2,dp));
}
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,nums.size()-1,dp);
    }
};