// https://leetcode.com/problems/symmetric-tree

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
    void fun1(TreeNode* root,vector<int>&v1){
        if(root==NULL) return;
        if(root->right==NULL or root->left==NULL){
        v1.push_back(-1);
        }
        fun1(root->left,v1);
        v1.push_back(root->val);
        fun1(root->right,v1);
    }
    void fun2(TreeNode* root,vector<int>&v2){
        if(root==NULL) return;
        if(root->right==NULL or root->left==NULL){
            v2.push_back(-1);
            // return;
        }
        fun2(root->right,v2);
        v2.push_back(root->val);
        fun2(root->left,v2);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int>v1;
        vector<int>v2;
        fun1(root,v1);
        fun1(root,v2);
        bool f=false;
        for(int i=0;i<v1.size() and v2.size();i++){
            if(v1[i]!=v2[i]){
                f=true;
                break;
            }
        }
        if(f){
            return false;
        }
        else{
            return true;
        }
    }
};