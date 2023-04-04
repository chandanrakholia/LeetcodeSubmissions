// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>vec;
        int t = 0;
        for(int i=0;i<=n;i++){
            int bits = 0;
            for(int j=0;j<=t;j++){
                if(i & (1<<j)){
                    bits++;
                }
            }
            if(bits == 1){
                t++;
            }
            vec.push_back(bits);
        }
        return vec;
    }
};