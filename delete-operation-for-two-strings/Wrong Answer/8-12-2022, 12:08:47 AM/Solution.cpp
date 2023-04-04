// https://leetcode.com/problems/delete-operation-for-two-strings

class Solution {
public:
    int dp[501][501];
    int solve(string &x,string &y,int n,int m){
        if(n==0 || m==0) dp[n][m]=0;
        if(dp[n][m]!=-1) return dp[n][m];
        else if(x[n-1]==y[m-1]) return 1+solve(x,y,n-1,m-1);
        else{
           return dp[n][m]=max(solve(x,y,n-1,m),solve(x,y,n,m-1));
        }
        return x.length()-dp[n][m]+y.length()-dp[n][m];
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,word1.length(),word2.length());
    }
};