// https://leetcode.com/problems/simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        stack<char>st;
        int x=path.length();
        for (int i = 0; i <x; i++)
        {
            if (st.size()==0 and path[i]=='/')
            {
                st.push(path[i]);
            }
            else if (path[i]=='/' and st.top()=='/')
            {
                st.pop();
            }
            else if (path[i]=='.')
            {
                continue;
            }
            else{
                st.push(path[i]);
            }
        }
        if(st.top()=='/' and st.size()>1){
            st.pop();
        }
        string ans="";
        if(st.size()==0){
            return ans;
        }
        
        else{
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        }
    }
};