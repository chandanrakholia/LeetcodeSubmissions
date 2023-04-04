// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    bool isPossible(int mid,vector<int>& nums, int k){
        int d=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                d++;
                sum=nums[i];
            }
        }
        return d<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        int mx=0;
        for(auto i: nums){
            sum+=i;
            mx=max(mx, i);
        }
        int lo=mx;
        int hi=sum;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isPossible(mid, nums, k)){
                hi=mid-1;
                ans=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};