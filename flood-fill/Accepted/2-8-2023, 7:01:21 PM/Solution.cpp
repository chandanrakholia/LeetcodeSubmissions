// https://leetcode.com/problems/flood-fill

class Solution {
    private:
        void dfs(int sr,int sc,vector<vector<int>>& image,int newcolour, int oldcolour){
            if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size()) return;
            if(image[sr][sc]==newcolour ||image[sr][sc]!=oldcolour ) return;
            image[sr][sc]=newcolour;
            dfs(sr,sc+1,image,newcolour, oldcolour);
            dfs(sr+1,sc,image,newcolour, oldcolour);
            dfs(sr-1,sc,image,newcolour, oldcolour);
            dfs(sr,sc-1,image,newcolour, oldcolour);
        }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(sr,sc,image, color, image[sr][sc]);
        return image;
    }
};