// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        int n=words.size();
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        vector<string>ans;
        for(int i=0;i<k;i++){
            int maxi=INT_MIN;
            map<string,int>::iterator kk;
            for(auto j=mp.begin();j!=mp.end();j++){
                if(j->second>maxi){
                    maxi=j->second;
                    kk=j;
                }

            }
            ans.push_back(kk->first);
            mp.erase(kk->first);
        }
            return ans;
        
    }
};