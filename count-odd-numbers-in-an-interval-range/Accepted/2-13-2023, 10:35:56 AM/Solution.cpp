// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range

class Solution {
public:
    int countOdds(int low, int high) {
        int x=high-low+1;
        int ans=x/2;
        if(low&1){
            if(x%2==0) ans=x/2;
            else ans++;
        }
        return ans;
    }
};