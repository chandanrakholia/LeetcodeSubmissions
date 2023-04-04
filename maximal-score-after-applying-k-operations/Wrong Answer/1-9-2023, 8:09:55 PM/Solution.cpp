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
            float p=ceil(top*10*.1/3);
            long long int add=ceil(p);
            pq.pop();
            pq.push(add);
        }
        return ans;
    }
};