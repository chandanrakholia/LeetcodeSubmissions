// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    void solve(vector<int>& nums, set<vector<int> > &s, vector<int> &temp, int i){
        if(i==nums.size()){
            vector<int> t=temp;
            sort(t.begin(), t.end());
            s.insert(t);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, s, temp, i+1);
        temp.pop_back();
        solve(nums, s, temp, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int> > s;
        vector<int> temp;
        solve(nums, s, temp, 0);
        vector<vector<int> > ans;
        for(auto i: s){
            ans.push_back(i);
        }
        return ans;
    }
};