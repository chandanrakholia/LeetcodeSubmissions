// https://leetcode.com/problems/sum-of-left-leaves

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
    int fun(TreeNode* root){
        if(root!=NULL){
            if(root->left&& !root->left->left && !root->left->right){
                return root->left->val+fun(root->left)+fun(root->right);
            }
        }
        return 0;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return fun(root);
    }
};