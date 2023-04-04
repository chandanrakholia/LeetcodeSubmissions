// https://leetcode.com/problems/count-vowel-strings-in-ranges

class Solution {
public:
    bool check(string s){
        int n=s.length();
        if((s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u') and (s[n-1]=='a' || s[n-1]=='e' || s[n-1]=='i' || s[n-1]=='o' || s[n-1]=='u')){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>pre(n+1);
        if(check(words[0])) pre[1]=1;
        for(int i=1;i<n;i++){
            pre[i+1]=pre[i];
            if(check(words[i])){
                pre[i+1]+=1;
            }
        }
        n=queries.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int x=queries[i][0];
            int y=queries[i][1];
            ans[i]=pre[y+1]-pre[x];
        }
        return ans;
    }
};