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
    bool solve(TreeNode* node)
    {
        if(node->val < 2)  return node->val;

        else if(node->val == 2) return solve(node->left) | solve(node->right);
        else return solve(node->left) & solve(node->right);
        
    }
public:
    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};