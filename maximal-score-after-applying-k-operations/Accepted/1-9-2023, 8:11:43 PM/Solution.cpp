// https://leetcode.com/problems/maximal-score-after-applying-k-operations

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long int>pq;
        for(auto i: nums){
            pq.push(i);
        }
        long long int ans=0;
        while(k--){
            long long int top=pq.top();
            ans+=pq.top();
            int add;
            if(pq.top()%3==0){
                add=pq.top()/3;
            }
            else{
                add=(pq.top()/3)+1;
            }
            pq.pop();
            pq.push(add);
        }
        return ans;
    }
};