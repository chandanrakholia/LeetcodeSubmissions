// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int dp[1001][1001];
//     int solve(string &x,string &y,int n,int m){
//         if(n==0 || m==0) dp[n][m]=0;
//         if(dp[n][m]!=-1) return dp[n][m];
//         else if(x[n-1]==y[m-1]) return 1+solve(x,y,n-1,m-1);
//         else{
//            return dp[n][m]=max(solve(x,y,n-1,m),solve(x,y,n,m-1));
//         }
        
//     }
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
    int longestPalindromeSubseq(string s) {
    string rev;
        int n=s.length();
    for (int i = n - 1; i >= 0; i--)
        rev.push_back(s[i]);
        return solve(s,rev,s.length(),rev.length());
    }
};