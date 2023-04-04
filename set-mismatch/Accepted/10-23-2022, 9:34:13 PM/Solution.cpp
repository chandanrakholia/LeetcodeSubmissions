// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int arr[10001]={0};
        arr[0]=-1;
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        vector<int>v;
        for(int i=1;i<nums.size()+1;i++){
            if(arr[i]==2){
                v.push_back(i);
            }
        }
        for(int i=1;i<nums.size()+1;i++){
            if(arr[i]==0){
                v.push_back(i);
            }
        }
        return v;
    }
};