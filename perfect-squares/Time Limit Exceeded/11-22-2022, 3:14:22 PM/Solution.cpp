// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        int arr[101];
        arr[0]=-1;
        for(int i=1;i<101;i++){
            arr[i]=i*i;
        }
        int idx=-1;
        for(int i=1;i<101;i++){
            if(arr[i]>=n){
                idx=i;
                break;
            }
        }
        queue<vector<int>>q;
        q.push({n,0});
        while(!q.empty()){
            vector<int> t=q.front();
            q.pop();
            if(t[0]<0) continue;
            if(t[0]==0){
                return t[1];
            }
            for(int i=1;i<100;i++){
            cout<<"check"<<endl;
                if(arr[i]<=t[0]){
                    q.push({t[0]-arr[i],t[1]+1});
                }
            }
        }
        return n;
    }
};