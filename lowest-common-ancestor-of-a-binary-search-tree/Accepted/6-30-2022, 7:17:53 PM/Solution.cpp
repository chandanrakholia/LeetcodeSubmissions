// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool findPath(TreeNode *root, vector<int> &path, int k)
{
    if (root == NULL) return false;
    path.push_back(root->val);
    if (root->val == k)
        return true;
    if ( (root->left && findPath(root->left, path, k)) ||
         (root->right && findPath(root->right, path, k)) )
        return true;
    path.pop_back();
    return false;
}
TreeNode* findLCA(TreeNode *root, int n1, int n2)
{
    vector<int> path1, path2;
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
          return NULL;
    int i;
    for (i = 0; i < path1.size() && i < path2.size() ; i++)
        if (path1[i] != path2[i])
            break;
    TreeNode* n=new TreeNode(path1[i-1]);
    return n;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root,p->val,q->val);
    }
};