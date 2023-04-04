// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>vec;
        int t = 0;
        vec.push_back(0);
        for(int i=1;i<=n;i++){
            if(i == (1<<t)){
                t++;
                vec.push_back(1);
            }
            else if(i%2 != 0){
                vec.push_back(vec[i-1]+1);
            }
            else{
                vec.push_back(1+vec[i-(1<<(t-1))]);
            }
        }
        return vec;
    }
};