// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int fib(int n) {
        int prev2=0;
        int prev1=1;
        int curr;
        for(int i=2;i<n+1;i++){
            curr=prev2+prev1;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};