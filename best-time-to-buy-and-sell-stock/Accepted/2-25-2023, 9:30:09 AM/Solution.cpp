// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int solve(vector<int>& prices){
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            profit=max(profit,prices[i]-mini);
            if(mini>prices[i]) mini=prices[i];
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};