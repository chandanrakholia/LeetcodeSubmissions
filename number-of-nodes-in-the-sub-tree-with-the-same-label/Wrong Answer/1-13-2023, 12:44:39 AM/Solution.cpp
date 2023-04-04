// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label

#include<bits/stdc++.h>
class Solution {
public:
void dfs(int node, vector<int> &ans,unordered_map<int, list<int> > &adj, unordered_map<int, bool> &visited , string labels,  map<char, int> &alpha){
    int prev=alpha[labels[node]];
    visited[node]=true;
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(i, ans, adj, visited, labels, alpha);
        }
    }
    alpha[labels[node]]++;
    ans[node]=alpha[labels[node]]-prev;

}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, list<int> > adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n);
        unordered_map<int, bool> visited;
        map<char, int> alpha;
        int node=edges[0][0];
        dfs(node, ans, adj, visited, labels, alpha);
        return ans;
    }
};