// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        vector<int>ans;
        for(int i=temperatures.size()-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(0);
            }
            else if (temperatures[i]<st.top().first)
            {
                ans.push_back(st.top().second-i);
            }
            else if(temperatures[i]>=st.top().first){
                while(st.size()!=0 and temperatures[i]>=st.top().first){
                    st.pop();
                }
                if(st.empty()){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(st.top().second-i);
                }
            }
            st.push({temperatures[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};