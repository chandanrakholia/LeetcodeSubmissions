// https://leetcode.com/problems/largest-perimeter-triangle

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int a=nums[0];
        int b=nums[1];
        int c=nums[2];
        if(a<b+c && b<a+c && c<a+b){
            return a+b+c;
        }
        return 0;
    }
};