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
    // int sum = 0;
    int inord(TreeNode* node, int lo, int hi)
    {
        if(!node) return 0;
        
        int lt = 0, vale = 0, rt=0;
        lt = inord(node->left,lo,hi);
        if(node->val <= hi && node->val >= lo)  vale = node->val;
        rt = inord(node->right,lo,hi);
        
        // cout<<node->val<<" "<<lt<<" "<<rt<<endl;
        
        return (lt+rt+vale);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return inord(root,low,high);
        
    }
};