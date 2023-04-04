// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
	    int r=n-1;
	    int mid=-1;
        int k=-1;
	    while(l<=r){
            int mid=l+(r-l)/2;
	        int prev=(mid-1+n)%n;
	        int next=(mid+1)%n;
	        if(nums[mid]==target){
	            // return mid;
                k=mid;
                break;
	        }
	        if(nums[mid]>=nums[r]){
	            l=mid+1;
	        }
	        else{
	            r=mid-1;
	        }
	    }
        
	    return k;
    }
};