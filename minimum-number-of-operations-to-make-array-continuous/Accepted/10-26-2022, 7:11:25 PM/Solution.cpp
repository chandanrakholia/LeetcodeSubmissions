// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int>set;
        for(auto i: nums) set.insert(i);
        vector<int>v;
        for(auto it: set) v.push_back(it);
        sort(v.begin(),v.end());
        int mini=INT_MAX;
        for(int i=0;i<v.size();i++){
            vector<int>::iterator upper=upper_bound(v.begin(),v.end(),v[i]+n-1);
            int len=upper-v.begin();
            mini=min(mini,n-(len-i));
        }
        return mini;
    }
};