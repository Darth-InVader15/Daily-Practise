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
    void trav(TreeNode* node,vector<int> &arr)
    {
        if(!node)   return;

        if(!node->left && !node->right) arr.push_back(node->val);
        trav(node->left,arr);
        trav(node->right,arr);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> arr1,arr2;

        trav(root1,arr1);
        trav(root2,arr2);

        return arr1 == arr2;
        
    }
};