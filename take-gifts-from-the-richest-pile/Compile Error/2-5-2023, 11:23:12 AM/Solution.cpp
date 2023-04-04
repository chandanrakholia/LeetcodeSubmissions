// https://leetcode.com/problems/take-gifts-from-the-richest-pile

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long >pq;
        for(auto i: gifts){
            pq.push(i);
        }
        for(int i=0;i<k;i++){
            long lon int f=pq.top();
            pq.pop();
            int s=sqrt(f);
            pq.push(s);
        }
        long long int ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};