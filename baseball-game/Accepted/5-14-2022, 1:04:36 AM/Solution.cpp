// https://leetcode.com/problems/baseball-game

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        int sum=0;
        int z;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){
                st.pop();
            }
                        else if(ops[i]=="D"){
                st.push(2*(st.top()));
            }
            else if(ops[i]=="+"){
                int p=st.top();
                st.pop();
                int q=st.top();
                st.push(p);
                st.push(p+q);
            }
            else{
                z=stoi(ops[i]);
                st.push(z);
            }
        }
                    while(!st.empty()){
                sum=sum+st.top();
                st.pop();
            }
        return sum;
    }
};