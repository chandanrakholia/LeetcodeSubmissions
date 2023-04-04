// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int x=n/2;
        for(int i=-x;i<0;i++){
            ans.push_back(i);
        }
        if(n%2!=0){
            ans.push_back(0);
        }
        for(int i=1;i<=x;i++){
            ans.push_back(i);
        }
        return ans;
    }
};