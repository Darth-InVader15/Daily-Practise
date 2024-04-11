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
    int solve(TreeNode* node, int num)
    {
        num = num*10 + node->val;
        
        //you have encountered a leaf node
        if(!node->left && !node->right) return num;

        int lt = 0, rt = 0;
        if(node->left)  lt = solve(node->left,num);
        if(node->right) rt = solve(node->right,num);

        return lt + rt;
    }
public:
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};