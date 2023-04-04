// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int flag=0;
        if(n==0 or n==1){
            flag=1;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
                nums.erase(nums.begin()+i);
            }

        }
                for(int i=0;i<count;i++){
            nums.push_back(0);
        }
        // return nums;
    }
};