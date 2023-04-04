// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int solve(vector<int>&nums,int n,vector<int>&dp){
    if(n==0) return dp[n]=nums[0];
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    return  dp[n]=max(nums[n]+solve(nums,n-2,dp),solve(nums,n-1,dp));
}
    int solve2(vector<int>&nums,int n,vector<int>&dp1){
        if(n==1) return nums[1];
    if(n==0) return 0;
    if(n<0) return 0;
    if(dp1[n]!=-1) return dp1[n];
    return  dp1[n]=max(nums[n]+solve2(nums,n-2,dp1),solve2(nums,n-1,dp1));
}
    int rob(vector<int>& nums) {
    int i=nums.size();
    vector<int>dp(i+1,-1);
    vector<int>dp1(i+1,-1);
    return max(solve(nums,i-2,dp),solve2(nums,i-1,dp1));
        // return solve2(nums,i-1,dp1);
    }
};