// https://leetcode.com/problems/burst-balloons

class Solution {
private:
    void print(vector<vector<int>>&dp){
        for(auto i: dp){
            for(auto j: i){
                cout<<j<<"   ";
            }
            cout<<endl;
        }
    }
    void solve(vector<int>& arr, int &ans){
        int n=arr.size();
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        vector<vector<int>>dp(n+2, vector<int>(n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int maxi=INT_MIN;
                for(int k=i;k<=j;k++){
                    int cost=arr[i-1]*arr[k]*arr[j+1]+dp[i][k-1]+dp[k+1][j];
                    maxi=max(maxi,cost);
                }
                dp[i][j]=maxi;
            }
        }
        ans=dp[1][n];
        print(dp);
    }
public:
    int maxCoins(vector<int>& nums) {
        int ans=0;
        solve(nums, ans);
        return ans;
    }
};