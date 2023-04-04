// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    int dp[101][10001];
    int solve(string x,string y,int n,int m){
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<m+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(x[i-1]==y[j-1]) 
                    dp[i][j]=dp[i-1][j-1]+1;
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    bool isSubsequence(string s, string t) {
        if(solve(s,t,s.length(),t.length())==s.length()){
            return true;
        }
        else{
            return false;
        }
    }
};