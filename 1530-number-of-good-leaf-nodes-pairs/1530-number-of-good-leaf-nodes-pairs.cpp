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
    void trav(TreeNode* node, map<TreeNode*,vector<TreeNode*>> &adj,set<TreeNode*> &leaf)
    {
        if(!node)   return;

        if(node->left)
        {
            adj[node].push_back(node->left);
            adj[node->left].push_back(node);
            trav(node->left,adj,leaf);
        }
        if(node->right)
        {
            adj[node].push_back(node->right);
            adj[node->right].push_back(node);
            trav(node->right,adj,leaf);
        }
        if(!node->left && !node->right) leaf.insert(node);
    }
    int dfs(TreeNode* node,int cnt,int ext,map<TreeNode*,vector<TreeNode*>> &adj, set<TreeNode*> &leaf,set<TreeNode*> &stt)
    {
        if(cnt>ext) return 0;
        if(leaf.count(node))    return 1; //reached a leaf node

        int ans = 0;
        stt.insert(node);
        for(auto x:adj[node])
        {
            if(!stt.count(x))    ans += dfs(x,cnt+1,ext,adj,leaf,stt);
        }
        return ans;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        map<TreeNode*,vector<TreeNode*>> adj;
        set<TreeNode*> leaf;
        trav(root,adj,leaf);

        int ans = 0;
        auto vis = leaf;
        for(auto x:leaf)
        {
            set<TreeNode*> stt;
            auto node = x;
            vis.erase(x);
            ans += dfs(node,0,distance,adj,vis,stt);
        }
        return ans;
    }
};