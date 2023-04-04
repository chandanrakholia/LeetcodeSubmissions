// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        for(int i=0;i<numRows;i++){
            vector<int>p(i+1,1);
            for(int j=2;j<=i;j++){
                p[j-1]=v[i-1][j-1]+v[i-1][j-2];
            }
            v.push_back(p);
        }
        return v;
    }
};