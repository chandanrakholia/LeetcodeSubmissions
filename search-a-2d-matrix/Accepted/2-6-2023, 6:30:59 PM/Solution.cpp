// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
bool bs(vector<vector<int>>& mat, int l, int r, int x, int col)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (mat[m/col][m%col] == x)
            return true;
        if (mat[m/col][m%col] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}
    bool solve(vector<vector<int>>& matrix, int target){
        int n=matrix.size();
        int m=matrix[0].size();
        int total=n*m;
        return bs(matrix, 0, total-1, target, m);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return solve(matrix, target);
    }
};