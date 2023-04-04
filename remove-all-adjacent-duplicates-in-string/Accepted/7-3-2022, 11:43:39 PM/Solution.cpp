// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        string st="";
        int x=s.size();
        for(int i=0;i<x;i++){
            if(st.empty()){
                st.push_back(s[i]);
            }
            else if(s[i]==st.back()){
                st.pop_back();
            }
            else{
                st.push_back(s[i]);
            }
        }
        return st;
    }
};