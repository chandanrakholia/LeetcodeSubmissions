// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int bsearch(vector<int>&nums,int l,int r,int target){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
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
	        if(nums[mid]<nums[next] && nums[mid]<nums[prev]){
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
        if(n==1){
            if(nums[0]==target) return 0;
            else return -1;
        }
            int x=bsearch(nums,0,k-1,target);
            int y=bsearch(nums,k,n,target);
            if(x!=-1) return x;
            else return y;
    }
};