// https://leetcode.com/problems/invert-binary-tree

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
    void solver(TreeNode* root){
        if(!root) return;
        swap(root->left, root->right);
        solver(root->left);
        solver(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        solver(root);
        return root;
    }
};