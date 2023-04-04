// https://leetcode.com/problems/distinct-subsequences

class Solution {
private:
    int solver(string &s, string &t, int ind1, int ind2, vector<vector<int>>&dp){
        if(ind2==0) return 1;
        if(ind1==0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s[ind1-1]==t[ind2-1]){
            return dp[ind1][ind2]=solver(s,t,ind1-1, ind2-1, dp) + solver(s,t,ind1-1, ind2, dp);
        }
        else{
            return dp[ind1][ind2]=solver(s,t,ind1-1,ind2, dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solver(s,t,n,m,dp);
    }
};