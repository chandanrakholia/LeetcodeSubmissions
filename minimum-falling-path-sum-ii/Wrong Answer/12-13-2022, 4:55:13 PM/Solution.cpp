// https://leetcode.com/problems/minimum-falling-path-sum-ii

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
                        int mini=INT_MAX;
                        for(int k=1;k<n;k++){
                            mini=min(mini,matrix[i-1][k]);
                        }
                        matrix[i][j]=mini+matrix[i][j];
                    }
                    else if(j==n-1){
                            int mini=INT_MAX;
                            for(int k=0;k<n-1;k++){
                                mini=min(mini,matrix[i-1][k]);
                            }
                            matrix[i][j]=mini+matrix[i][j];
                    }
                    else{
                        int mini=INT_MAX;
                        for(int k=0;k<n and k!=j;k++){
                            mini=min(mini,matrix[i-1][k]);
                        }
                        matrix[i][j]=mini+matrix[i][j];
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