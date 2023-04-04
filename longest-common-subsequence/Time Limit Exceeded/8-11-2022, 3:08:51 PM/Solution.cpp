// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int dp[1001][1001];
    int solve(string x,string y,int n,int m){
        if(n==0 || m==0) dp[n][m]=0;
        if(dp[n][m]!=-1) return dp[n][m];
        else if(x[n-1]==y[m-1]) return 1+solve(x,y,n-1,m-1);
        else{
           return max(solve(x,y,n-1,m),solve(x,y,n,m-1));
        }
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int n=text1.length();
        int m=text2.length();
        return solve(text1,text2,n,m);
    }
};