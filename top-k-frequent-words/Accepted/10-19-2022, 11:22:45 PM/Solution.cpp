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
            map<string,int>::iterator k;
            for(auto j=mp.begin();j!=mp.end();j++){
                if(j->second>maxi){
                    maxi=j->second;
                    k=j;
                }

            }
            ans.push_back(k->first);
            mp.erase(k->first);
            // sort(ans.begin(),ans.end());
        }
            return ans;
        
    }
};