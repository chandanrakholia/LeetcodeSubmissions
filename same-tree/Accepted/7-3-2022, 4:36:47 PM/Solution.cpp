// https://leetcode.com/problems/same-tree

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
    // void sametree(TreeNode* p,TreeNode* q,int *f){
    //     if(p==NULL and q==NULL){
    //         return;
    //     }
    //     if(p->val != q->val){
    //         f=0;
    //         return;
    //     }
    //     sametree(p->left,q->left, f);
    //     sametree(p->right,q->right,f);
    // }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL){
            return true;
        }
        else if((p==NULL and q!=NULL) or (p!=NULL and q==NULL) or (p->val != q->val)){
            return false;
        }
        return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
    }
};