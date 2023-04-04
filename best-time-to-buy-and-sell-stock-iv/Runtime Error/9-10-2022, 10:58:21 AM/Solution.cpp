// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
        int arr[1000][1000]={0};
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n==0 || n==1) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    arr[i][j]=-1;
                }
                if(j<=i){
                    arr[i][j]=-1;
                }
                else{
                    arr[i][j]=prices[j]-prices[i];
                }
            }
        }
        vector<int>v;
        int maxi1=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]!=-1){
                    v.push_back(arr[i][j]);
                }
            }
        }
        sort(v.begin(),v.end(),greater<int>());
        long long int ans=0;
        for(int i=0;i<k;i++){
            if(v[i]>0)
            ans+=v[i];
        }
        
        return ans;
        
    }
};