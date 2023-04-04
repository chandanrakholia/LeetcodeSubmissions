// https://leetcode.com/problems/ipo

class Solution {
private:
void print(vector<pair<int,int>>&v){
    for(auto i: v){
        cout<<i.first<<" "<<i.second<<endl;
    }
}
    int solver(int k, int w, vector<int>& profits, vector<int>& capital){
        vector<pair<int,int>>v;
        int n=profits.size();
        for(int i=0;i<n;i++){
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        if(k==0) return w;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            if(k==0) return w;
            if(v[i].first<=w){
                pq.push(v[i].second); //i.second=profits;
            }
            else{
                w+=pq.top();
                pq.pop();
                k--;
                i--;
            }
        }
        while(k--){
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        return solver(k,w,profits,capital);
    }
};