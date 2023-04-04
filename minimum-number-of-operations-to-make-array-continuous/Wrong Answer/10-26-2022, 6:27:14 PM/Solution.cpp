// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous

class Solution {
public:
    int binarySearch(vector<int>&arr, int l, int r, int x)
    {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int ans=0;
        for(int i=a;i<a+n;i++){
            if(binarySearch(nums,0,n-1,i)==-1){
                ans++;
            }
        }
        return ans;
        
    }
};