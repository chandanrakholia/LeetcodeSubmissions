// https://leetcode.com/problems/minimum-time-to-complete-trips

class Solution {
public:
    long long help(vector<int>&time ,int mid){
        long long cnt=0; 
        for(auto i:time){
            cnt+=mid/i;
        }
        return cnt;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int low=1;
        long long int high=1e14;
        while(low<=high){
            long long int mid=(low+high)/2;
            long long cnt=0; 
            for(auto i:time){
                cnt+=mid/i;
            }
            if(cnt<totalTrips){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};