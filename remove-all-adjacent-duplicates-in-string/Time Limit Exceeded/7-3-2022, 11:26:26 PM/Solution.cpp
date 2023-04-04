// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int x=s.length();
        for(int i=0;i<x;i++){
            if(st.size()==0){
                st.push(s[i]);
            }
            else if(s[i]==st.top()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(st.size()>0){
            ans=ans+st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};