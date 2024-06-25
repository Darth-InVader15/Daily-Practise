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
    // int solve(TreeNode* node, map<TreeNode*,int> &mpp, map<TreeNode*, TreeNode*> &par)
    // {
    //     if(!node)   return 0;

    //     if(node->left) par[node->left] = node;
    //     if(node->right) par[node->right] = node;

    //     if(par[node] && par[node]->val > node->val)  //we are in the left node now
    //     {
    //         node->val += par[node]->val;
    //     }

    //     int rt = solve(node->right,mpp,par);
    //     // mpp[node] = node->val + rt;
    //     node->val += rt;
    //     int lt = solve(node->left,mpp,par);

    //     return max(node->val, lt);
    // }
    void trav(TreeNode* node, vector<int> &arr)
    {
        if(!node)   return;

        trav(node->left,arr);
        arr.push_back(node->val);
        trav(node->right,arr);
    }
    void fix(TreeNode* node,int &ind, vector<int> &arr)
    {
        if(!node)   return;

        fix(node->left,ind,arr);
        node->val = arr[ind++];
        fix(node->right,ind,arr);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        // it is fairly simple for the right half, add sum of the left subtree for all nodes
        vector<int> arr;
        trav(root,arr);
        int sum = 0;

        for(int i=arr.size()-1;i>=0;i--)
        {
            sum += arr[i];
            arr[i] = sum;
        }
        int ind = 0;
        fix(root,ind,arr);
        return root;
        
    }
};