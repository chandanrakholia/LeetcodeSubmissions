// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int solve(string s, string t, int x, int y, vector<vector<int> > &dp){
        if(x==0) return y;
        if(y==0) return x;
        if(dp[x][y]!=-1) return dp[x][y];
        if(s[x-1]==t[y-1]) return dp[x][y]=solve(s, t, x-1, y-1, dp);
        else{
            int insert=1+solve(s,t,x,y-1, dp);
            int del=1+solve(s,t,x-1, y, dp);
            int replace=1+solve(s,t, x-1, y-1, dp);
            return dp[x][y]=min(min(insert,del), replace);
        }
    }
    int minDistance(string word1, string word2) {
        /*Using DP - Concept of LCS*/
        vector<vector<int> > dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        return solve(word1, word2, word1.length(), word2.length(), dp);
    }
};