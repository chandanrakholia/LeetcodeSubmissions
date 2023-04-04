// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int m=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        int n=nums.end()-upper_bound(nums.begin(),nums.end(),0);
        return max(m,n);
    }
};