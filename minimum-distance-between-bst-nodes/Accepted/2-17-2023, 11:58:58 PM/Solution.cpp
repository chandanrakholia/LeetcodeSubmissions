// https://leetcode.com/problems/minimum-distance-between-bst-nodes

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
    int mini=INT_MAX;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev!=NULL){
            mini=min(mini,root->val-prev->val);
        }
        prev=root;
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return mini;
    }
};