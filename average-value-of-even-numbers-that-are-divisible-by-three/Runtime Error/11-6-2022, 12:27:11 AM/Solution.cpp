// https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int ans=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%6==0){
                ans+=nums[i];
                count++;
            }
        }
        return ans/count;
    }
};