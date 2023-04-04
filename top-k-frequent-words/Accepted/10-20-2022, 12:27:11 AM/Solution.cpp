// https://leetcode.com/problems/top-k-frequent-words

// #include<bits/stdc++.h>
    bool comp(pair<string, int> &p1,pair<string, int> &p2){
    if(p1.second==p2.second) 
        return p1.first < p2.first;
    return p1.second > p2.second;
    }
class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++) mp[words[i]]++;
        vector<pair<string,int>>v;
        for(auto i: mp){
            v.push_back({i.first,i.second});
        }
        sort(v.begin(),v.end(), comp);
        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};