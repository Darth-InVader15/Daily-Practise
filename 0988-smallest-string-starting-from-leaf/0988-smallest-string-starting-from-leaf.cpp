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
    // time/space: O(n)/O(h)
    string smallestFromLeaf(TreeNode* root) {
        // DFS
        string s = "", result = "";
        helper(root, s, result);
        return result;
    }
private:
    void helper(TreeNode* node, string& s, string& result) {
        // teminate
        if (node == NULL) return;

        // enumerate
        s.push_back(node->val + 'a');
        if ((node->left == NULL) && (node->right == NULL)) {
            string t = s;
            reverse(t.begin(), t.end());
            if (result.empty() || (t < result)) result = t;
        }
        else {
            helper(node->left, s, result);
            helper(node->right, s, result);
        }
        s.pop_back();
    }
};