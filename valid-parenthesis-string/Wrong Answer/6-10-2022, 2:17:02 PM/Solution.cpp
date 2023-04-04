// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    bool checkValidString(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if((s[i]=='*' and st.top()=='(') or (s[i]==')' and st.top()=='(') or(s[i]==')' and st.top()=='*')){
                st.pop();
            }
            
        }
        int count=0;
        while(!st.empty()){
            if(st.top()=='('){
                count++;
            }
            st.pop();
        }
        if(count>0){
            return false;
        }
        else{
            return true;
        }
        
    }
};