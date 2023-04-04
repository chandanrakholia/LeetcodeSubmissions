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
            else(
            st.push(s[i]));
            
        }
        int count=0;
        while(!st.empty()){
            if(st.top()=='('){
                count++;
                return false;
            }
            st.pop();
        }
        // if(count>0){
        //     return false;
        // }
        // else{
        //     return true;
        // }
        return true;
    }
};