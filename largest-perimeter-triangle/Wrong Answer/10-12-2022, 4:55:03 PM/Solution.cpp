// https://leetcode.com/problems/largest-perimeter-triangle

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[n-1]+nums[n-2];
        for(int i=n-3;i>=0;i--){
            if(nums[i]+nums[n-2]>nums[n-1]){
                ans+=nums[i];
                return ans;
            }
        }
        return 0;
    }
};