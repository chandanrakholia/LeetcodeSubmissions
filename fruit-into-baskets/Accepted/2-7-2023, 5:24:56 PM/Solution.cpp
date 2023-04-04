// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int help(map<int,int>&mp){
        int cnt=0;
        for(auto i=mp.begin();i!=mp.end();i++){
            cnt+=i->second;
        }
        return cnt;
    }
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0;
        int j=0;
        map<int,int>mp;
        int cnt=INT_MIN;
        while(i<n){
            mp[fruits[i]]++;
            if(mp.size()<=2){
                cnt=max(cnt, help(mp));
            }
            if(mp.size()>2){
                while(mp.size()>2){
                    if(--mp[fruits[j]]==0) mp.erase(fruits[j]);
                    j++;
                }
            }
            i++;
        }
        return cnt;
    }
};