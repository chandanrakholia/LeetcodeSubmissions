// https://leetcode.com/problems/rearranging-fruits

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<long long int,long long int> mp;
        for(auto i: basket1){
            mp[i]++;
        }
        for(auto i: basket2){
            mp[i]=abs(mp[i]-1);
        }
        long long int swapping=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            swapping+=it->second;
            if(it->second&1) return -1;
        }
        swapping/=2;
        long long int mini=mp.begin()->first;
        return mini*swapping;

    }
};