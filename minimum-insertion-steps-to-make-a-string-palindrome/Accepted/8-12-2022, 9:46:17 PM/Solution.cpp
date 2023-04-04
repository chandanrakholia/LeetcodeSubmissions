// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome

class Solution {
public:
        int dp[501][501];
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
    int minInsertions(string s) {
        string rev;
        int n=s.length();
    for (int i = n - 1; i >= 0; i--)
        rev.push_back(s[i]);
        return n-solve(s,rev,s.length(),rev.length());
        
    }
};