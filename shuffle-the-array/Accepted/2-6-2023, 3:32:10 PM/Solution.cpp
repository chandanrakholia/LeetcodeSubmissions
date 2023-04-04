// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> myorginal(vector<int>& nums, int n){
        vector<int>ans;
        int i=0;
        int j=n;
        while(j < 2*n){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;j++;
        }
        return ans;
    }
    vector<int> anotherwayofimplementation(vector<int>& nums, int n){
        vector<int>ans(2*n);
        for(int i=0;i<n;i++){
            ans[2*i]=nums[i];
            ans[2*i+1]=nums[n+i];
        }
        return ans;
    }
    vector<int> shuffle(vector<int>& nums, int n) {
        // return myoriginal(nums, n);
        return anotherwayofimplementation(nums, n);
    }
};