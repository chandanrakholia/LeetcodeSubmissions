// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool f=false;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<k;j++){
                if(nums[i]==nums[j]){
                    f=true;
                }
            }
        }
        return f;
    }
};