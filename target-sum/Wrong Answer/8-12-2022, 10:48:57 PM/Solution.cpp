// https://leetcode.com/problems/target-sum

class Solution {
public:
    typedef long long int ll;
    int findTargetSumWays(vector<int>& nums, int target) {
        ll s=accumulate(nums.begin(),nums.end(),0);
        if((target+s)%2!=0) return 0;
        int sum=(target+s)/2;
        int n=nums.size();
        ll t[n + 1][sum + 1];
        for (ll i = 0; i <= n; i++)
            t[i][0] = 1;
        for (ll i = 1; i <= sum; i++)
            t[0][i] = 0;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= sum; j++) {
                if (nums[i - 1] <= j)
                    t[i][j] = t[i - 1][j] + t[i - 1][j - nums[i - 1]];
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        return t[n][sum];
    }
};