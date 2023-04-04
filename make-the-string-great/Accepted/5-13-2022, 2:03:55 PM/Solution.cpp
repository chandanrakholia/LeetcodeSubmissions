// https://leetcode.com/problems/make-the-string-great

class Solution {
public:
    string makeGood(string s) {
        if(s.size()==1){
            return s;
        }
        int n=s.size();
        string str="";
        
        stack<char>stack;
        
        for(int i=0;i<n;i++){
            if(stack.empty()){
                stack.push(s[i]);
            }
            else{
                if((int(stack.top())-int(s[i])==32) || (int(stack.top())-int(s[i])==-32)){
                    stack.pop();
                }
                else{
                    stack.push(s[i]);
                }
            }
            }
                    while(!stack.empty()){
                        str=str+stack.top();
                        stack.pop();
                    }
                    reverse(str.begin(), str.end());
                    return str;
        
        }
        
};