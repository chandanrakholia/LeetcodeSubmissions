// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>ump;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++;
        }
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto i=ump.begin();i!=ump.end();i++){
            pq.push({i->second,i->first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};