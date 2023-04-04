// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int bs(vector<int>& nums, int target){
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            cout<<mid<<endl;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return 0;
    }
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        // return bs(nums, target);
    }
};