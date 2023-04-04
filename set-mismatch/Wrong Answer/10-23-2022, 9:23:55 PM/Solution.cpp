// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=1;i<=nums.size();i++){
            if(nums[i-1]!=i){
                ans.push_back(nums[i-1]);
                ans.push_back(i);
            }
        }
        return ans;
    }
};