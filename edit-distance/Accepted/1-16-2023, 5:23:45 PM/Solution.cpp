// https://leetcode.com/problems/edit-distance

class Solution {
public:
    void print(vector<vector<int> > &dp){
        for(auto i: dp){
            for(auto j: i){
                cout<<j<< ' ';
            }
            cout<<endl;
        }
    }
    int solve(string s, string t, int x, int y, vector<vector<int> > &dp){
        if(x==0) return y;       /*TC word1.length() * word2.length()*/ /*SC word1.length() * word2.length()*/
        if(y==0) return x;       /*Using recursion+Memoization*/
        if(dp[x][y]!=-1) return dp[x][y];
        if(s[x-1]==t[y-1]) return dp[x][y]=solve(s, t, x-1, y-1, dp);
        else{
            int insert=1+solve(s,t,x,y-1, dp);
            int del=1+solve(s,t,x-1, y, dp);
            int replace=1+solve(s,t, x-1, y-1, dp);
            return dp[x][y]=min(min(insert,del), replace);
        }
    }
    int solveTab(string s, string t, int x, int y){ 
        vector<vector<int> > dp(s.length()+1, vector<int>(t.length()+1, 0));
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                else if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    int insert=1+dp[i][j-1];
                    int del=1+dp[i-1][j];
                    int replace=1+dp[i-1][j-1];
                    dp[i][j]=min(min(insert,del), replace);
                }
            }
        }
        return dp[x][y];
    }
    int solveTabSO(string s, string t, int x, int y){
        /*t is small y is small*/
        vector<int> prev(y+1, 0);
        vector<int> curr(y+1, 0);
        for(int i=0;i<=y;i++){
            prev[i]=i;    /*TC N*M*/        /*SC MIN(word1.length(), word2.length())*/
        }
        for(int i=1;i<=x;i++){
            curr[0]=i;
            for(int j=1;j<=y;j++){
                if(s[i-1]==t[j-1]) curr[j]=prev[j-1];
                else{
                    int insert=1+curr[j-1];
                    int del=1+prev[j];
                    int replace=1+prev[j-1];
                    curr[j]=min(min(insert,del), replace);
                }
            }
            prev=curr;
        }
        return prev[y];
    }
    int minDistance(string word1, string word2) {
        /*Using DP - Concept of LCS*/
        // vector<vector<int> > dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        // int ans=solve(word1, word2, word1.length(), word2.length(), dp);
        // int ans=solveTab(word1, word2, word1.length(), word2.length());
        // print(dp);
        int ans;
        if(word1.size()<=word2.size()){
            ans=solveTabSO(word2, word1, word2.length(), word1.length());
        }
        else{
            ans=solveTabSO(word1, word2, word1.length(), word2.length());
        }
        return ans;
    }
};