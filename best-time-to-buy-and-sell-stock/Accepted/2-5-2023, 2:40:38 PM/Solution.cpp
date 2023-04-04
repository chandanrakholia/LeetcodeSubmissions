// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof=0;
        int n =prices.size();
        int mini=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i] < mini){
                mini=min(mini, prices[i]);
            }
            else{
                prof=max(prof, prices[i] - mini);
            }
        }
        return prof;
    }
};