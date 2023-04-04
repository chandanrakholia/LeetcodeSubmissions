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
        if(n==2){
            if(nums[0]==target) return 0;
            if(nums[1]==target) return 1;
            else return -1;
        }
	    return k;
    }
};