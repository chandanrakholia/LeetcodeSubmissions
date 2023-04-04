// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int r=x;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid*mid==x){
                ans=mid;
                return ans;
            }
            else if(mid*mid<x){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};