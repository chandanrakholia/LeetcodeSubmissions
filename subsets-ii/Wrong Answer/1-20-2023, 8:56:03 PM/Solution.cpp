// https://leetcode.com/problems/subsets-ii

class Solution {
public:
        void solve(vector<int>& nums, vector<vector<int> > &ans, vector<int> &temp, int i){
        sort(temp.begin(), temp.end());
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, ans, temp, i+1);
        temp.pop_back();
        solve(nums, ans, temp, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> temp;
        solve(nums, ans, temp, 0);
        set<vector<int> > st;
        for(auto i: ans){
            sort(i.begin(), i.end());
            st.insert(i);
        }
        vector<vector<int> > final;
        for(auto i: st){
            final.push_back(i);
        }
        return final;
    }
};