// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int isum=0;
        for(int i=0;i<n;i++) isum+=nums[i];
        set<int>s;
        for(int i=0;i<n;i++) s.insert(nums[i]);
        int sum=0;
        for(auto i=s.begin();i!=s.end();i++) sum+=*i;
        vector<int>v;
        v.push_back(isum-sum);
        int x=n*(n+1)/2;
        v.push_back(x-sum);
        return v;
    }
};