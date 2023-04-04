// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    int t[300][20000];
    bool fun(vector<int>arr,int sum,int n){
        if(sum==0) return true;
        if(n==0) return false;
        if (t[n - 1][sum] != -1)
        return t[n - 1][sum];
        if(arr[n-1] > sum) 
        return t[n-1][sum]=fun(arr,sum,n-1);
        else{
               return t[n-1][sum]=fun(arr,sum,n-1) || fun(arr, sum - arr[n - 1],n-1);
        }
}
    bool canPartition(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        long long int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        if(s%2==0){
            bool f=fun(nums,s/2,nums.size());
            return fun(nums,s/2,nums.size());
        }
        else{
            return false;
        }

    }
};