// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
private:
    void print(vector<int> &v){
        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    vector<int> smallestright(vector<int>&h){
        int n=h.size();
        vector<int>v;
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                v.push_back(n);
            }
            else if(h[i]>st.top().first){
                v.push_back(st.top().second);
            }
            else{
                while(!st.empty() and st.top().first>=h[i]){
                    st.pop();
                }
                if(st.empty()){
                    v.push_back(n);
                }
                else{
                    v.push_back(st.top().second);
                }
            }
            st.push({h[i],i});
        }
        reverse(v.begin(), v.end());
        return v;
    }
    vector<int> smallestleft(vector<int>&h){
        int n=h.size();
        vector<int>v;
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                v.push_back(0);
            }
            else if(h[i]>st.top().first){
                v.push_back(st.top().second+1);
            }
            else{
                while(!st.empty() and st.top().first>=h[i]){
                    st.pop();
                }
                if(st.empty()){
                    v.push_back(0);
                }
                else{
                    v.push_back(st.top().second+1);
                }
            }
            st.push({h[i],i});
        }
        return v;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>right=smallestright(heights);
        vector<int>left=smallestleft(heights);
        // print(left);
        int n=heights.size();
        if(n==1) return heights[0];
        int maxi=0;
        print(left);
        print(right);
        for(int i=0;i<n;i++){
            maxi=max(maxi, (right[i]-left[i])*heights[i]);
        }
        return maxi;
    }
};