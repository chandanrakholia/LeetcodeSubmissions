// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char>st;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(st.size()==0){
                st.push(s[i]);
            }
            else if(s[i]==')' and st.top()=='('){
                count=count+2;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return count;
    }
};