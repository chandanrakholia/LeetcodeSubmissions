// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<long long int>st;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"){
                int n2=st.top();
                st.pop();
                int n1=st.top();
                st.pop();
                st.push(n1+n2);
            }
            else if(tokens[i]=="-"){
                int n2=st.top();
                st.pop();
                int n1=st.top();
                st.pop();
                st.push(n1-n2);
            }
            else if(tokens[i]=="*"){
                int n2=st.top();
                st.pop();
                int n1=st.top();
                st.pop();
                st.push(n1*n2);
            }
            else if(tokens[i]=="/"){
                int n2=st.top();
                st.pop();
                int n1=st.top();
                st.pop();
                st.push(n1/n2);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};