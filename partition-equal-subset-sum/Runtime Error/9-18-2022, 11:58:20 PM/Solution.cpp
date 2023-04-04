// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool knap(vector<int>&nums,int n,int tar,vector<vector<int>>&v){
        if(tar==0) return true;
        if(n==0) return false;
        if(v[n][tar]!=-1) return v[n][tar];
        if(nums[n]>tar){
            return v[n][tar]=knap(nums,n-1,tar,v);
        }
        else{
            return v[n][tar]=max(knap(nums,n-1,tar,v),knap(nums,n-1,tar-nums[n],v));
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==0){
            vector<vector<int>>v;
            vector<int>v1;
            for(int j=0;j<=sum/2;j++){
            for(int i=0;i<=nums.size();i++){
            v1.push_back(-1);
            }
                v.push_back(v1);
        }
            if(knap(nums,nums.size()-1,sum/2,v)){
                return true;
            }
            return false;
        }
        return false;
    }
};