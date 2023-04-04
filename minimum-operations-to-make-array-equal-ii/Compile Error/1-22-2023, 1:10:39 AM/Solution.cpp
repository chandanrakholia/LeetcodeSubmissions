// https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long int inc=0;
        long long int dec=0;
        for(log long int i=0;i<nums1.size();i++){
            if(nums1[i]==nums2[i]) continue;
            else if(nums1[i]>nums2[i] and (nums1[i]-nums2[i])%k==0){
                dec+=(nums1[i]-nums2[i])/k;
            }
            else if(nums1[i]<nums2[i] and (nums1[i]-nums2[i])%k==0){
                inc+=(nums2[i]-nums1[i])/k;
            }
            else{
                return -1;
            }
        }
        if(inc==dec) return inc;
        return -1;
    }
};