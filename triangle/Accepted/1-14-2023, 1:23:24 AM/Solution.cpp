// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int> > dp(triangle.size(), vector<int>(triangle.size()));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            int x=triangle[i].size();
            for(int j=0;j< x;j++){
                if(j==0){
                    dp[i][j]=dp[i-1][j]+triangle[i][j];
                }
                else if(j==x-1){
                    dp[i][j]=dp[i-1][j-1]+triangle[i][j];
                }
                else{
                    dp[i][j]=min(dp[i-1][j]+triangle[i][j], dp[i-1][j-1]+triangle[i][j]);
                }
            }
        }
        for(auto i: dp){
            for(auto j: i){
                cout<<j<<' ';
            }
            cout<<endl;
        }
        int mn=INT_MAX;
        for(int i=0;i<dp[triangle.size()-1].size();i++){
            if(dp[triangle.size()-1][i]<mn){
                mn=dp[triangle.size()-1][i];
            }
        }
        return mn;
    }
};