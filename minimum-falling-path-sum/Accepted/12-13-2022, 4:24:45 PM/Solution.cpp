// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    matrix[i][j]=matrix[i][j];
                }
                else{
                    if(j==0){
                        matrix[i][j]=min(matrix[i-1][j],matrix[i-1][j+1])+matrix[i][j];
                    }
                    else if(j==n-1){
                        matrix[i][j]=min(matrix[i-1][j-1],matrix[i-1][j])+matrix[i][j];
                    }
                    else{
                        matrix[i][j]=min(min(matrix[i-1][j-1],matrix[i-1][j]),matrix[i-1][j+1])+matrix[i][j];
                    }
                }

            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<' ';
            }
            cout<<endl;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini, matrix[n-1][i]);
        }
        return mini;
    }
};