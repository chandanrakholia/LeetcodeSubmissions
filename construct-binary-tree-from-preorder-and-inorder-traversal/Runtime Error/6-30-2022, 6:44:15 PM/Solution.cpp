// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    int search(vector<int>in,int start,int end,int curr){
    for (int i = start; i <=end; i++)
    {
        if (in[i]==curr)
        {
            return i;
        }
        
    }
    return -1;   
}
TreeNode* buildTree1(vector<int>in,vector<int>pre,int start,int end){
    static int idx=0;
    if(start>end) return NULL;
    int curr=pre[idx];
    idx++;
    TreeNode* node=new TreeNode(curr);
    if(start==end){
        return node;
    }
    int pos=search(in,start,end,curr);
    node->left=buildTree1(in,pre,start,pos-1);
    node->right=buildTree1(in,pre,pos+1,end);
    return node;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int end=preorder.size()-1;
        TreeNode* root=buildTree1(inorder,preorder,0,end);
            return root;
    }
};