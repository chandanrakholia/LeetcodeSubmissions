// https://leetcode.com/problems/max-points-on-a-line

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2) return n;
        int ans=0;
        for(auto it1: points){
            unordered_map<double,int>mp;
            double x1=it1[0];
            double y1=it1[1];
            for(auto it2: points){
                if(it1==it2) continue;
                double x2=it2[0];
                double y2=it2[1];
                double slope;
                if(x1==x2){
                    slope=INT_MAX;
                }
                else{
                    slope=(y2-y1)/(x2-x1);
                }
                mp[slope]++;
                ans=max(ans,mp[slope]);
            }
        }
        ans++;
        return ans;
    }
};