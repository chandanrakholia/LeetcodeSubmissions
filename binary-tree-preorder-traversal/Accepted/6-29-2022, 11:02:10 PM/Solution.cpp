// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    void preordertrav(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        v.push_back(root->val);
        preordertrav(root->left,v);
        preordertrav(root->right,v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* temp=root;
        vector<int>v;
        preordertrav(root, v);
        return v;
    }
};