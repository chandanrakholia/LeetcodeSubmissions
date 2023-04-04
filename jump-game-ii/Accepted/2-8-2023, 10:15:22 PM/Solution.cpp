// https://leetcode.com/problems/jump-game-ii

class Solution {
private:
    int mem(vector<int>& nums, int ind, vector<int>&dp){
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int mini=1e9;
        for(int i=1;i<=1000;i++){
            if(ind-i>=0 && nums[ind-i]>=i){
                int temp=mem(nums, ind-i, dp) + 1;
                mini=min(mini, temp);
            }
        }
        return dp[ind]=mini;
    }
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1, -1);
        return mem(nums, n-1, dp);
    }
};