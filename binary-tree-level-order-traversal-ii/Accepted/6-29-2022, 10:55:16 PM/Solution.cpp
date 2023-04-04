// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
                
        vector<vector<int>>v;
        if(root==NULL)
            return v;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.size()>0){
            int n=q.size();
            vector<int>x;
            for(int i=0;i<n;i++){
                TreeNode* t=q.front();
                q.pop();
                x.push_back(t->val);
                
                if(t->left!=NULL )
                    q.push(t->left); 
                if(t->right!=NULL)
                    q.push(t->right);
            }
            v.push_back(x);
        }
        reverse(v.begin(),v.end());
        
        return v;
    }
};