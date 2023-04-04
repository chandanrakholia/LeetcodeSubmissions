// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(k==0) return 0;
        int n=nums.size();
        int pre[n];
        pre[0]=nums[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i];
        int idx=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(pre[i]%k==0){
                idx=i;
            }
            if(idx!=-1){
                if((pre[i]-pre[idx])/k==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};