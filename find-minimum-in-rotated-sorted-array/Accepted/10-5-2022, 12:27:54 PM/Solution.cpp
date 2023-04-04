// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
	    int r=nums.size()-1;
	    int x=nums[n-1];
	    int a=-1;
	    while(l<=r){
	        int m=l+(r-l)/2;
	        if(nums[m]==x) return nums[n-1];
	        if(nums[m]<x) r=m-1;
	        else {
	            l=m+1;
	            a=m;
	        }
	    }
	    // if(a!=-1)
	    return nums[a+1];
	    // else{
	    //     return 0;
	    // }
    }
};