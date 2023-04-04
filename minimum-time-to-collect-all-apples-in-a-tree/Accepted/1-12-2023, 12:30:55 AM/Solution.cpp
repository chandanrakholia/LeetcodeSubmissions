// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree

class Solution {
public:
int dfs(int start,int n,vector<bool> &visited, unordered_map<int, list<int> > &adj, vector<bool>& hasApple){
    int time=0;
    for(auto i: adj[start]){
        if(!visited[i]){
            visited[i]=true;
            int child=dfs(i, n, visited, adj, hasApple);
            if(hasApple[i] || child){
                time+=child+2;
            }
            cout<<i<<" -> "<<child<<" "<<time<<endl;
        }
    }
    return time;
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, list<int> > adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        visited[0]=true;
        return dfs(0, n, visited, adj, hasApple);
    }
};