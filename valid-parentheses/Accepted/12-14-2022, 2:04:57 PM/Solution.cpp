// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(st.size()==0){
                st.push(s[i]);
            }
            else if(s[i]==')' and st.top()=='('){
                st.pop();
            }
            else if(s[i]=='}' and st.top()=='{'){
                st.pop();
            }
            else if(s[i]==']' and st.top()=='['){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};