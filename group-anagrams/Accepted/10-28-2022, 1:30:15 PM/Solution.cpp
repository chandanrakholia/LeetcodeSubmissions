// https://leetcode.com/problems/group-anagrams

#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>>v;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string p=strs[i];
            sort(strs[i].begin(),strs[i].end());
            v.push_back({strs[i],p});
        }
        sort(v.begin(),v.end());
        vector<vector<string>>ans;
        vector<string>x;
        x.push_back(v[0].second);
        string prev=v[0].first;
        for(int i=1;i<n;i++){
            if(v[i].first!=prev){
                ans.push_back(x);
                x.clear();
            }
            x.push_back(v[i].second);
            prev=v[i].first;
        }
        if(x.size()>0) ans.push_back(x);
        return ans;
    }
};