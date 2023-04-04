// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        vector<int>v;
        for(auto it1=mp.begin();it1!=mp.end();it1++){
            for(auto it2=mp.begin();it2!=mp.end() and it2!=it1;it2++){
                if(it1->first+it2->first==target){
                    v.push_back(it1->second);
                    v.push_back(it2->second);
                    break;
                }
            }
        }
        return v;
    }
};