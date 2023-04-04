// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1, 0);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        for(int i=0;i<dp.size();i++){
            cout<<dp[i]<<' ';
        }
        return dp[n];
    }
};