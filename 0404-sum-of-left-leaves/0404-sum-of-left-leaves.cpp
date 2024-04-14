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
private:
    int solve(TreeNode* node)
    {
        if(!node)   return 0;

        if(node->left && !node->left->left && !node->left->right)
            return node->left->val + solve(node->right);

        int lt = solve(node->left);
        int rt = solve(node->right);

        return lt+rt;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root);
    }
};