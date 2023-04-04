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
    int solverdp(string &s, string &t){
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        //base case
        for(int i=0;i<=m;i++) dp[0][i]=0;
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
    long long int solverdpSO(string &s, string &t){
        int n=s.length();
        int m=t.length();
        // vector<vector<int>>dp(n+1, vector<int>(m+1));
        vector<long long int>prev(m+1), curr(m+1);

        //base case
        for(int i=0;i<=m;i++) prev[i]=0;
        prev[0]=1;
        for(int i=1;i<=n;i++){
            curr[0]=1;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=prev[j-1] + prev[j];
                }
                else{
                    curr[j]=prev[j];
                }
            }
            prev=curr;
        }
        return prev[m];
    }
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        // return solver(s,t,n,m,dp);
        return solverdp(s,t);
        // return solverdpSO(s,t);
    }
};