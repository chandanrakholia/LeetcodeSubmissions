// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    long long int getcnt(vector<int>& w, int mid){
        long long int cnt=0;
        for(auto i: w){
            cnt+=ceil(i/(double)mid);
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=0;
        int mn=1;
        for(auto w: piles){
            mx=max(mx, w);
        }
        int lo=mn;
        int hi=mx;
        int ans=0;
        while(lo<=hi){
            int mid=lo + (hi-lo)/2;
            long long int temp=getcnt(piles, mid);
            if(temp<=h){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
            cout<<"checked"<<endl;
        }
        return ans;
    }
};