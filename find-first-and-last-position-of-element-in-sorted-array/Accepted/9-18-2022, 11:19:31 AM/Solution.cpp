// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    int BSearch1(vector<int>&nums,int start,int end,int target){
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                ans=mid;
                end=end-1;
            }
            else if(target<nums[mid]) end=end=mid-1;
            else start=mid+1;
        }
        return ans;
    }
        int BSearch2(vector<int>&nums,int start,int end,int target){
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                ans=mid;
                start=start+1;
            }
            else if(target<nums[mid]) end=end=mid-1;
            else start=mid+1;
        }
            return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v;
        v.push_back(BSearch1(nums,0,nums.size()-1,target));
        v.push_back(BSearch2(nums,0,nums.size()-1,target));
        return v;
    }
};