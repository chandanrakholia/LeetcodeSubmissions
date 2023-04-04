// https://leetcode.com/problems/subsets-ii

class Solution {
public:
        void solve(vector<int>& nums, vector<vector<int> > &ans, vector<int> &temp, int i){
        if(i==nums.size()){
            if(ans.size()>0 and ans.back()==temp){
                return;
            }
            else{
                ans.push_back(temp);
                return;
            }
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
        return ans;
    }
};