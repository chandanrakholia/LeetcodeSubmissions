// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int itl=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int itu=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        vector<int>ans;
        ans.push_back(itl);
        ans.push_back(itu-1);
        return ans;
    }
};