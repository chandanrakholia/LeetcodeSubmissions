// https://leetcode.com/problems/sort-array-by-increasing-frequency

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>ump;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++;
        }
        priority_queue <pair<int,int>>pq;
        for(auto i=ump.begin();i!=ump.end();i++){
            pq.push({-i->second,i->first});
        }
        vector<int>ans;
        while(!pq.empty()){
            for(int i=0;i<-pq.top().first;i++)
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};