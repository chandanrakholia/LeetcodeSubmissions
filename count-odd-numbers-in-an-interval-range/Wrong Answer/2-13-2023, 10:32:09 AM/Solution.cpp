// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range

class Solution {
public:
    int countOdds(int low, int high) {
        int x=high-low+1;
        int ans;
        if(low&1) ans=ceil(x*.1*10/2);
        else ans=x/2;
        return ans;
    }
};