// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    long long int evalRPN(vector<string>& tokens) {
        long long int n=tokens.size();
        stack<long long int>st;
        for(long long int i=0;i<n;i++){
            if(tokens[i]=="+"){
                long long int n2=st.top();
                st.pop();
                long long int n1=st.top();
                st.pop();
                st.push(n1+n2);
            }
            else if(tokens[i]=="-"){
                long long int n2=st.top();
                st.pop();
                long long int n1=st.top();
                st.pop();
                st.push(n1-n2);
            }
            else if(tokens[i]=="*"){
                long long int n2=st.top();
                st.pop();
                long long int n1=st.top();
                st.pop();
                st.push(n1*n2);
            }
            else if(tokens[i]=="/"){
                long long int n2=st.top();
                st.pop();
                long long int n1=st.top();
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