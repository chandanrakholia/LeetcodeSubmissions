// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        for(auto i=mp.begin();i!=mp.end();i++){
            pq.push({i->second,i->first});
            if(pq.size()>k) pq.pop();
        }
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};