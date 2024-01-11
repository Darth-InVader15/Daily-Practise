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
    int trav(TreeNode* node, vector<int> val)
    {
        if(!node)   return 0;
        
        int curr = node->val;
        int lt=0,rt=0;
        
        val.push_back(curr);
        lt = trav(node->left,val);
        rt = trav(node->right,val);
        val.pop_back();
        
        int maxx = INT_MIN;
        for(auto x:val)
        {
            if(abs(x-curr) > maxx){
                maxx = max(maxx,abs(x-curr));
                // cout<<x<<" "<<curr<<" "<<maxx<<endl;
            }   
        }
        // cout<<lt<<" "<<rt<<endl;
        return max({maxx,lt,rt});
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        vector<int> vale;
        vale.push_back(root->val);
        return trav(root,vale);
        
    }
};