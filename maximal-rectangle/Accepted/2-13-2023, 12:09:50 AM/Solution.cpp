// https://leetcode.com/problems/maximal-rectangle

class Solution {
private:
    void print(vector<vector<int>>&dp){
        for(auto i: dp){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    void smallestright(vector<int>&h, vector<int>&v, int n){
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
    }
    void smallestleft(vector<int>&h, vector<int>&v, int n){
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
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
       vector<vector<int>>dp(n, vector<int>(m)); 
       for(int i=0;i<m;i++){
           if(matrix[0][i]=='1'){
               dp[0][i]=1;
           }
           else{
               dp[0][i]=0;
           }
       }
       for(int i=1;i<n;i++){
           for(int j=0;j<m;j++){
               if(matrix[i][j]=='1') dp[i][j]=dp[i-1][j]+1;
               else dp[i][j]=0;
           }
       }
       int maxi=0;
       for(int k=0;k<n;k++){
            vector<int>right, left;
            smallestright(dp[k], right,m);
            smallestleft(dp[k], left,m);
            for(int i=0;i<m;i++){
                maxi=max(maxi, (right[i]-left[i])*dp[k][i]);
            }
       }
    //    print(dp);
       return maxi;
    }
};