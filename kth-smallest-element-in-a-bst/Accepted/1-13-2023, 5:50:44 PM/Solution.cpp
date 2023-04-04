// https://leetcode.com/problems/kth-smallest-element-in-a-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void preorder(TreeNode* root, vector<int> &v){
    if(root==NULL) return;
    preorder(root->left, v);
    v.push_back(root->val);
    preorder(root->right,v);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        preorder(root, v);
        priority_queue<int>pq;
        for(int i=0;i<v.size();i++){
            if(pq.size()<k){
                pq.push(v[i]);
            }
            else{
                if(pq.top()> v[i]){
                    pq.pop();
                    pq.push(v[i]);
                }
            }
        }
        return pq.top();
    }
};