// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
private:
    int f1(vector<int>& prices, int &ind1, int &ind2){
        int prof=0;
        int n =prices.size();
        int mini=INT_MAX;
        int j=0;
        for(int i=0;i<n;i++){
            if(prices[i] <= mini){
                mini=prices[i];
                j=i;
            }
            else if(prices[i]-mini>prof){
                prof=prices[i]-mini;
                ind1=j;
                ind2=i;
            }

        }
        return prof;
    }
    int f2(vector<int>& prices, int ind1, int ind2){
        int prof=0;
        int n =prices.size();
        int mini=INT_MAX;
        for(int i=0;i<ind1;i++){
            if(prices[i] < mini){
                mini=prices[i];
            }
            else{
                if(prices[i]-mini>prof){
                    prof=prices[i]-mini;
                }
            }
        }
        mini=INT_MAX;
        for(int i=ind2+1;i<n;i++){
            if(prices[i] < mini){
                mini=prices[i];
            }
            else{
                if(prices[i]-mini>prof){
                    prof=prices[i]-mini;
                }
            }
        }
        return prof;
    }
public:
    int maxProfit(vector<int>& prices) {
        int x=-1;int y=-1;
        int ans=f1(prices, x, y);
        cout<<x<<" "<<y<<endl;
        ans+=f2(prices, x, y);
        return ans;
    }
};