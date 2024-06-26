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
 //Divide and Conquer just like merge sort
class Solution {
    void trav(TreeNode* node, vector<int> &arr)
    {
        if(!node)   return ;
        trav(node->left,arr);
        arr.push_back(node->val);
        trav(node->right,arr);
    }
    TreeNode* makeTree(int l, int r, vector<int> arr)
    {
        if(l>=r) return NULL;
        int mid = (l+r)/2;

        TreeNode* node = new TreeNode(arr[mid]);
        node->left = makeTree(l,mid,arr);
        node->right = makeTree(mid+1,r,arr);

        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        //idk inorder store krke root ko middle ele leke?
        vector<int> arr;
        trav(root,arr);
        return makeTree(0,arr.size(),arr);
    }
};