// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char>st;
        vector<int>v;
        int count=0;
        st.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(st.size()==0){
                st.push(s[i]);
                count=0;
            }
            else if(s[i]==')' and st.top()=='('){
                count=count+2;
                st.pop();
            }
            else{
                st.push(s[i]);
                count=0;
            }
            v.push_back(count);
        }
        return *max_element(v.begin(),v.end());
    }
};