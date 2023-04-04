// https://leetcode.com/problems/simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string s = "";
        path += '/';
        for(int i=1;i<=path.length();i++){
            if(path[i] == '/'){
                if(s == ".." and !st.empty()){
                    st.pop();
                }
                else if(s!="." and !s.empty()/* and s!=".."*/){
                    st.push(s);
                }
                s = "";
            }
            else{
                s+=path[i];
            }
        }
        string s2 = "";
        stack<string>st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        if(st2.empty()){
            s2+='/';
        }
        while(!st2.empty()){
            s2+='/';
            s2+=st2.top();
            st2.pop();
        }
        return s2;
        
    }
};