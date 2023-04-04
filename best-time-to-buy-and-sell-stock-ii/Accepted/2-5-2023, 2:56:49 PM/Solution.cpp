// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int n=prices.size();
        int prof=0;
        for(int i=1;i<n;i++){
            if(prices[i] < mini){
                mini=min(mini, prices[i]);
            }
            else {
                prof+=prices[i]-mini;
                mini=prices[i];
            }
        }
        return prof;
    }
};