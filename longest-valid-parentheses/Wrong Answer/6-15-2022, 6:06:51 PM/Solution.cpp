// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char>st;
        vector<int>v;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
                count=0;
            }
            else if(s[i]==')' and st.top()=='('){
                count=count+2;  
            }
            else if(st.top() == '(' and s[i] == '('){
                v.push_back(count);
                count=0;
            }
            else if(st.top() == ')' and s[i] == ')'){
                v.push_back(count);
                count=0;
            }
            st.push(s[i]);   
        }
        v.push_back(count);
        return *max_element(v.begin(),v.end());
    }
};