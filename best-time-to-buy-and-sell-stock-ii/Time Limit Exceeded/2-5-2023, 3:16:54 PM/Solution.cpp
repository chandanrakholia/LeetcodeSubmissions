// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int optimized(vector<int>& prices){
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
    int bruteforceutility(vector<int>& prices, int s){
        int n=prices.size();
        if(s>=n) return 0;
        int maxi=0;
        for(int start=s;start<n;start++){
            for(int i=start+1;i<n;i++){
                if(prices[i] > prices[start]){
                    maxi =max(maxi,   bruteforceutility(prices, i+1) + prices[i]-prices[start]);
                }
            }
        }
        return maxi;
    }
    int bruteforce(vector<int> &prices){
        return bruteforceutility(prices, 0);
    }
    int maxProfit(vector<int>& prices) {
        // return optimized(prices);
        return bruteforce(prices);
    }
};