// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(st.empty()==true){
                st.push(s[i]);
            }
            else if(s[i]==')' and st.top()=='(' ){
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
        // string str="";
        if(st.empty()==true){
            return "true";
        }
        else{
            return "false";
        }
    }
};