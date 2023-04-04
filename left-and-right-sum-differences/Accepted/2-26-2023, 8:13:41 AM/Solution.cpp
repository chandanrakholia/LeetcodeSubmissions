// https://leetcode.com/problems/left-and-right-sum-differences

class Solution {
public:
    void print(vector<int>&nums){
        for(auto i:nums) cout<<i<<endl;
        cout<<endl;
    }
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n), right(n);
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+nums[i-1];
        }
        for(int i=1;i<n;i++){
            right[n-i-1]=right[n-i]+nums[n-i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=abs(right[i]-left[i]);
        }
        print(right);
        print(left);
        return ans;
    }
};