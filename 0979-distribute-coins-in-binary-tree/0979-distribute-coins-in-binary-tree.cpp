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
    int cnt = 0;
    int dfs(TreeNode* node)
    {
        if(!node)   return 0;

        int lt = dfs(node->left);
        int rt = dfs(node->right);

        int tot = lt+rt+node->val -1;
        cnt+= abs(lt) + abs(rt);
        return tot;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};