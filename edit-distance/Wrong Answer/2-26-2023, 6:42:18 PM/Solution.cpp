// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int solve(string &s, string &t, int ind1, int ind2,vector<vector<int>>&dp){
        if(ind1==0 and ind2==0) return 0;
        if(ind1==0 || ind2==0) return 1e8;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s[ind1-1]==t[ind2-1]){
            return dp[ind1][ind2]=solve(s,t,ind1-1, ind2-1,dp)+0;
        }
        else{
            int del=solve(s,t,ind1-1,ind2,dp);
            int rep=solve(s,t,ind1-1,ind2-1,dp);
            int ins=solve(s,t,ind1, ind2-1,dp);
            return dp[ind1][ind2]=min({del,rep,ins})+1;
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(word1, word2, n, m, dp);
    }
};