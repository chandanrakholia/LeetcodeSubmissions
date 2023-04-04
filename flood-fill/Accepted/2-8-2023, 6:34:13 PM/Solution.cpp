// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> mat=image;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int oldColor=image[sr][sc];
        queue<vector<int>>q;
        q.push({sr,sc});
        while(!q.empty()){
            vector<int>v=q.front();
            q.pop();
            if(v[0]<0 || v[0]>=n || v[1]<0 || v[1]>=m) continue;
            if(vis[v[0]][v[1]]==true) continue;
            vis[v[0]][v[1]]=true;
            if(image[v[0]][v[1]]==oldColor){
                mat[v[0]][v[1]]=color;
                q.push({v[0]+1, v[1]});
                q.push({v[0], v[1]+1});
                q.push({v[0]-1, v[1]});
                q.push({v[0], v[1]-1});
            }
        }
        return mat;
    }
};