// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
        int dp[1001][1001];
    
    string rev(string &s){
        string r="";
        for(int i=s.length()-1;i>=0;i--){
            r+=s[i];
        }
        return r;
    }

        string solve(string &x,string &y,int n,int m){
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
                    dp[i][j]=0;
                }
            }
        }
            int i=x.length();
            int j=y.length();
            string str;
            while(i>0 && j>0 ){
                if(x[i-1]==y[j-1]){
                    str.push_back(x[i-1]);
                    i--;
                    j--;
                }
                else{
                    if(dp[i][j-1]>dp[i-1][j]){
                        j--;
                    }
                    else{
                        i--;
                    }
                }
            }
            return rev(str);
    }
    string longestPalindrome(string s) {
        string r=rev(s);
        return solve(s,r,s.length(),s.length());
    }
};