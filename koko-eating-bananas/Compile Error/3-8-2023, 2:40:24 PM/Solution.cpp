// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    long long int getcnt(vector<long long int>& w, long long int mid){
        long long int cnt=0;
        for(auto i: w){
            cnt+=ceil(i/(double)mid);
        }
        return cnt;
    }
    long long int minEatingSpeed(vector<long long int>& piles, long long int h) {
        long long int mx=0;
        long long int mn=1;
        for(auto w: piles){
            mx=max(mx, w);
        }
        long long int lo=mn;
        long long int hi=mx;
        long long int ans=0;
        while(lo<=hi){
            long long int mid=lo + (hi-lo)/2;
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