// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>v;
        vector<int>q;
        for(int i=0;i<rowIndex+1;i++){
            vector<int>p(i+1,1);
            for(int j=2;j<=i;j++){
                p[j-1]=v[i-1][j-1]+v[i-1][j-2];
            }
            v.push_back(p);
            q=p;
        }
        return q;
    }
};