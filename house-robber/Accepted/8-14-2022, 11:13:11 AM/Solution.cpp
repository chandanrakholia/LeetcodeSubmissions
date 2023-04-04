// https://leetcode.com/problems/house-robber

class Solution {
public:
    int solve(vector<int>&nums,int n,vector<int>&dp){
    if(n==0) return dp[0]=nums[0];
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    return  dp[n]=max(nums[n]+solve(nums,n-2,dp),solve(nums,n-1,dp));
}
    int rob(vector<int>& nums) {
    int i=nums.size();
    vector<int>dp(i+1,-1);
    return solve(nums,i-1,dp);
    }
};