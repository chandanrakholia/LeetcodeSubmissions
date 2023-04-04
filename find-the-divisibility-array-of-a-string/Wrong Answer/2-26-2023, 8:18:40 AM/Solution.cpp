// https://leetcode.com/problems/find-the-divisibility-array-of-a-string

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n=word.length();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int c=word[i]-'0';
            if(c%m==0){
                ans[i]=1;
            }
        }
        return ans;
    }
};