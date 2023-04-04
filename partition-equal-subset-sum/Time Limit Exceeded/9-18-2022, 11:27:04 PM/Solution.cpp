// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool knap(vector<int>nums,int n,int tar){
        if(tar==0) return true;
        if(n==0) return false;
        
        if(nums[n]>tar){
            return knap(nums,n-1,tar);
        }
        else{
            return max(knap(nums,n-1,tar),knap(nums,n-1,tar-nums[n]));
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==0){
            if(knap(nums,nums.size()-1,sum/2)){
                return true;
            }
            return false;
        }
        return false;
    }
};