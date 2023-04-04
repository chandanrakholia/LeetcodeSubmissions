// https://leetcode.com/problems/find-the-divisibility-array-of-a-string

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n=word.length();
        vector<int>ans(n);
        int prev=-1;
        for(int i=0;i<n;i++){
            int c=word[i]-'0';
            if(prev==-1){
                prev=c;
            }else
            prev=(prev*10%m+c%m)%m;
            if(prev%m==0){
                ans[i]=1;
            }
        }
        return ans;
    }
};