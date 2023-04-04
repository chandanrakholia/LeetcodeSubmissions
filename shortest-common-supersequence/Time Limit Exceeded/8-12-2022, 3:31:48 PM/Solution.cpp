// https://leetcode.com/problems/shortest-common-supersequence

class Solution {
public:
    string rev(string s){
        string r="";
        for(int i=s.length()-1;i>=0;i--){
            r+=s[i];
        }
        return r;
    }
        int dp[1001][1001];
        string solve(string x,string y,int n,int m){
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
                        str.push_back(y[j-1]);
                        j--;
                    }
                    else if(dp[i-1][j]>dp[i][j-1]){
                        str.push_back(x[i-1]);
                        i--;
                    }
                }
            }
            while(i>0){
                str.push_back(x[i-1]);
                i--;
            }
            while(j>0){
                str.push_back(y[j-1]);
                j--;
            }
            return rev(str);
    }
    string shortestCommonSupersequence(string str1, string str2) {
        return solve(str1,str2,str1.length(),str2.length());
    }
};