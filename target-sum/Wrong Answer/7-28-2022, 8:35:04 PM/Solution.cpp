// https://leetcode.com/problems/target-sum

class Solution {
public:
        int no_of_subset(vector<int>&arr,int n,int sum){
    int t[n+1][sum+1];
    // memset(t,0,sizeof(t));
    t[0][0]=1;
    for (int i = 1; i <= sum; i++)
    {
        t[0][i]=0;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            // if (i==0) return 0;
            // if (j==0) return 1;
            if (arr[i-1]<=j)
            {
                t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
            
        }
        
    }
    return t[n][sum];
    
}
    int findTargetSumWays(vector<int>& nums, int target) {
                int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        return no_of_subset(nums,nums.size(),(target+s)/2);
    }
};