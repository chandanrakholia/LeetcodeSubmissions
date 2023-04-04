// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label

#include<bits/stdc++.h>
class Solution {
public:
void dfs(int node,int prevnode, vector<int> &ans,unordered_map<int, list<int> > &adj, string &labels,  vector<int> &alpha){
    int prevcount=alpha[labels[node]-'a'];
    alpha[labels[node]-'a']++;
    for(auto i: adj[node]){
        if(i==prevnode) continue;
            dfs(i, node,  ans, adj,labels, alpha);
    }
    ans[node]=alpha[labels[node]-'a'] - prevcount;
    cout<<"node: "<<node<<" prevcount: "<<prevcount<<" "<<ans[node]<<endl; 
}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, list<int> > adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n, 0);
        vector<int> alpha(26, 0);
        dfs(0,0, ans, adj,labels, alpha);
        return ans;
    }
};