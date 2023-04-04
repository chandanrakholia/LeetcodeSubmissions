// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==0 or n==1)
            return nums;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
                nums.erase(nums.begin()+nums[i]);
            }

        }
                for(int i=0;i<count;i++){
            nums.pushback(0);
        }
        return nums;
    }
};