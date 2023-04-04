// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>pq;
        vector<vector<int>>ans;
        for(int i=0;i<points.size();i++){
            pq.push({pow(points[i][0],2)+pow(points[i][1],2),points[i]});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};