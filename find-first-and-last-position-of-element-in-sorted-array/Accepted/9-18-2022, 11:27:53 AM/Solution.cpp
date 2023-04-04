// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v;
        int l=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int u=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(l==u){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        v.push_back(l);
        v.push_back(u-1);
        return v;
    }
};