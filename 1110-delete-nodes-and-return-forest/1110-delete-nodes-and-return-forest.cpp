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
class DSU{
    public:
    vector<int> par,siz;
    DSU(int n)
    {
        par.resize(n+1);
        siz.resize(n+1,1);

        for(int i=1;i<=n;i++)   par[i] = i;
    }
    int findPar(int node)
    {
        if(par[node] == node)   return node;
        return findPar(par[node]);
    }
    void unionBySize(int u,int v)
    {
        cout<<"union of "<<u<<" "<<v<<endl;
        int pu = findPar(u), pv = findPar(v);
        if(pu == pv)    return;

        if(siz[pu] >= siz[pv])
        {
            siz[pu] += siz[pv];
            par[pv] = pu;
        }
        else
        {
            siz[pv] += siz[pu];
            par[pu] = pv;
        }
    }
};
class Solution {
    int trav(TreeNode* node, unordered_map<int,vector<int>> &adj,unordered_map<int,TreeNode*> &mpp)
    {
        if(!node)   return 0;
        int lt = 0, rt=0;
        mpp[node->val] = node;
        if(node->left)
        {
            adj[node->val].push_back(node->left->val);
            lt = trav(node->left,adj,mpp);
        }
        if(node->right)
        {
            adj[node->val].push_back(node->right->val);
            rt = trav(node->right,adj,mpp);
        }
        return 1+lt+rt; //count for tot nodes
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,TreeNode*> mpp;
        int n = trav(root,adj,mpp);

        DSU ds(n);
        unordered_set<int> del;
        for(auto x:to_delete)   del.insert(x);

        for(int i=1;i<=n;i++)
        {
            if(del.count(i))    continue;
            for(auto x:adj[i])
            {
                // cout<<i<<" - "<<x<<endl;
                if(!del.count(x))
                {
                    ds.unionBySize(i,x);
                }
                else //we are delete the child of node
                {
                    if(mpp[i]->left && mpp[i]->left->val == x) mpp[i]->left = NULL;
                    else mpp[i]->right = NULL;
                }
            }
        }
        unordered_set<int> ans;
        for(int i=1;i<=n;i++)
        {
            if(!del.count(i) && !ans.count(ds.findPar(i)))
                ans.insert(ds.findPar(i));
            // cout<<i<<" "<<ds.findPar(i)<<endl;
        }
        cout<<ans.size()<<endl;
        vector<TreeNode*> anss;
        for(auto x:ans)
        {
            anss.push_back(mpp[x]);
        }
        return anss;
    }
};