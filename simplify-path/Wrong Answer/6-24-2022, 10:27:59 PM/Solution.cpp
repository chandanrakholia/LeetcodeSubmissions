// https://leetcode.com/problems/simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        if(path[path.length()-1]!='/'){
            path+='/';
        }
        string s="";
        for (int i = 1; i < path.length(); i++)
        {
            if(path[i]=='/'){
                if(s=="."){
                    s="";
                }
                else if(s==".." and st.size()>0){
                    st.pop();
                    s="";
                }
                else if(s==".." and st.size()==0){
                    s="";
                }
                else{
                    st.push(s);
                    s="";
                }
            }
            else{
                s+=path[i];
            }

        }
        string slash="/";
        string ans="";
        if(st.size()==0){
            return "/";
        }
        else if(st.size()==1){
            ans+="/";
            ans+=st.top();
            st.pop();
            return ans;
        }
        else{
            while(st.size()>0){
                ans+='/';
                ans+=st.top();
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
};