// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    bool ispossible(vector<int>& w, int mid, int h){
        int cnt=0;
        for(auto i: w){
            if(i%mid==0){
                cnt+=i/mid;
            }
            else{
                cnt+=(1+ i/mid);
            }
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int sum=0;
        int mx=0;
        int mn=INT_MAX;
        for(auto w: piles){
            mx=max(mx, w);
            sum+=w;
            mn=min(mn, w);
        }
        int lo=mn;
        int hi=mx;
        int ans=0;
        while(lo<=hi){
            int mid=lo + (hi-lo)/2;
            if(ispossible(piles, mid, h)){
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