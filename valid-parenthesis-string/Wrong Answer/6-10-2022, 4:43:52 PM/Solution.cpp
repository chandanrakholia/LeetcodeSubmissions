// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    bool checkValidString(string s) {
        stack<char>st;
        int x=s.length();
        for(int i=0;i<x;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if((s[i]=='*' and st.top()=='(') or (s[i]==')' and st.top()=='(') or(s[i]==')' and st.top()=='*')){
                st.pop();
            }
            else{
            st.push(s[i]);
            }
        }
        string str="";
        while(!st.empty()){
            str=str+st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        for(int i=0;i<str.length();i++){
            if(str[i]==')'){
                return false;
            }
        }
        return true;
    }
};