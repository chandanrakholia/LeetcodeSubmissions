// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int pre[n];
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            pre[i]=pre[i]%k;
        }
        map<int,int>mp;
        mp[0]=0;
        for(int i=0;i<n;i++){
            if(mp.find(pre[i])!=mp.end()){
                if(i-mp[pre[i]]>=2){
                    return true;
                }
            }
            else{
                mp[pre[i]]=i; 
            }
        }
        return false;
    }
};