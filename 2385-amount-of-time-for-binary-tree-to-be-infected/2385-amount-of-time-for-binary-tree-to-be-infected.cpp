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
    int maxx = 0;
    void trav(TreeNode* node, unordered_map<int,vector<int>> &mpp)
    {
        if(!node) return;
        
        if(node->left)
        {
            mpp[node->val].push_back(node->left->val);
            mpp[node->left->val].push_back(node->val);
        }
        if(node->right)
        {
            mpp[node->val].push_back(node->right->val);
            mpp[node->right->val].push_back(node->val);
        }
        
        trav(node->left,mpp);
        trav(node->right,mpp);
    }
    
    void bfs(queue<pair<int,int>>&q, unordered_map<int,vector<int>> &mpp, unordered_set<int> &stt)
    {
        while(!q.empty())
        {
            auto curr = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(stt.count(curr)) continue;
            stt.insert(curr);
            // cout<<curr<<" "<<cnt<<endl;
            maxx = max(cnt,maxx);
            
            for(auto x:mpp[curr])
            {
                if(stt.count(x))   continue;
                q.push({x,cnt+1});
            }
        }
        
    }
    public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> graph;
        
        trav(root,graph);
        queue<pair<int,int>> q;
        unordered_set<int> stt;
        
        q.push({start,0});
        // stt.insert(start);
        bfs(q,graph,stt);
        
        return maxx;     
        
    }
};