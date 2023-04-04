// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int bruteforce(vector<int>& prices){
        int n=prices.size();
        int prof=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){

                prof=max(prof, prices[j]-prices[i]);
            }
        }
        return prof;
    }
    int optimized(vector<int>& prices){
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
    int maxProfit(vector<int>& prices) {
        return bruteforce(prices);
        // return optimized(prices);

    }
};