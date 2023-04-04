// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    bool ispossible(vector<int>& w, int mid, int days){
        int d=1;
        int sum=0;
        for(int i=0;i<w.size();i++){
            sum+=w[i];
            if(sum>mid){
                d++;
                sum=w[i];
            }
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int mx=0;
        for(auto w: weights){
            mx=max(mx, w);
            sum+=w;
        }
        int lo=mx;
        int hi=sum;
        int ans=0;
        while(lo<=hi){
            int mid=lo + (hi-lo)/2;
            if(ispossible(weights, mid, days)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};