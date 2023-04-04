// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
            }
            else if(!s.empty() and st.top()==s[i]){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        string ss;
        while(!st.empty()) {
            ss.push_back(st.top());
            st.pop();
        }
        reverse(ss.begin(),ss.end());
        return ss;

    }
};