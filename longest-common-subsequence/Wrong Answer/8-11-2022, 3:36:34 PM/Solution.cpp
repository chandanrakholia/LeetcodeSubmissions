// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int dp[1001][1001];
    int solve(string x,string y,int n,int m){
        for(int i=0;i<1001;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<1001;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(x[i-1]=y[j-1]) 
                    dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int n=text1.length();
        int m=text2.length();
        return solve(text1,text2,n,m);
    }
};