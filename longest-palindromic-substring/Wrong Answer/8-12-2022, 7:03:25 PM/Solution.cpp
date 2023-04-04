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
            int max=INT_MIN;
            int p=-1;
            int q=-1;
            for(int i=0;i<n+1;i++){
                for(int j=0;j<m+1;j++){
                    if(dp[i][j]>max){
                        max=dp[i][j];
                        p=i;
                        q=j;
                    }
                }
            }
            int i=p;
            int j=q;
            string str;
            while(i>0 && j>0 && dp[i][j]!=0){
                // if(x[i-1]==y[j-1] and dp[i][j]!=0){
                    str.push_back(x[i-1]);
                    i--;
                    j--;
                // }
            }
            return rev(str);
    }
    string longestPalindrome(string s) {
        string r=rev(s);
        return solve(s,r,s.length(),r.length());
    }
};