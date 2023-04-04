// https://leetcode.com/problems/edit-distance

class Solution {
public:
    void print(vector<vector<int>>&dp){
        for(auto i: dp){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    int solve(string &s, string &t, int ind1, int ind2,vector<vector<int>>&dp){
        if(ind1==0) return ind2;
        if(ind2==0) return ind1;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s[ind1-1]==t[ind2-1]){
            return dp[ind1][ind2]=solve(s,t,ind1-1, ind2-1,dp)+0;
        }
        else{
            int del=solve(s,t,ind1-1,ind2  ,dp);
            int rep=solve(s,t,ind1-1,ind2-1,dp);
            int ins=solve(s,t,ind1,  ind2-1,dp);
            return dp[ind1][ind2]=min({del,rep,ins})+1;
        }
    }
    int solvetab(string &s, string &t){
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        //base case
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=m;i++){
            dp[0][i]=i;
        }
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s[ind1-1]==t[ind2-1]){
                    dp[ind1][ind2]=dp[ind1-1][ind2-1]+0;
                }
                else{
                    int del=dp[ind1-1][ind2];
                    int rep=dp[ind1-1][ind2-1];
                    int ins=dp[ind1][ind2-1];
                    dp[ind1][ind2]=min({del,rep,ins})+1;
                }
            }
        }
        print(dp);
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        // int ans=solve(word1, word2, n, m, dp);
        // print(dp);
        // return ans;
        return solvetab(word1, word2);
    }
};