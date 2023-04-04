// https://leetcode.com/problems/minimize-deviation-in-array

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mini=INT_MAX;
        priority_queue<int>pq;
        for(auto &i: nums){
            if(i&1){
                i*=2;
            }
            pq.push(i);
            mini=min(mini, i);
        }
        int ans=INT_MAX;
        while(true){
            int top=pq.top();
            ans=min(ans, pq.top()-mini);
            if(pq.top()&1){
                break;
            }
            pq.pop();
            pq.push(top/2);
        }
        return ans;
    }
};