// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v;
        v.push_back(0);
        for(int i=1;i<=n;i++){
            if(i%2==0) v.push_back(1);
            else{
                v.push_back(v[i-1]+1);
            }
        }
        return v;
    }
};