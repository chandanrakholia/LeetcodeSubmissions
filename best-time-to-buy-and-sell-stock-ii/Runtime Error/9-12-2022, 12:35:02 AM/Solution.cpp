// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        long long int ans=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i+1]>prices[i]){
                ans+=prices[i+1]-prices[i];
            }
        }
        return ans;
    }
};