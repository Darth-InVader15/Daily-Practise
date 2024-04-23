class Solution {
private:
    int maxx = INT_MAX;
    vector<int> ans;

    void solve(int root, vector<vector<int>> &adj)
    {
        unordered_set<int> vis;
        queue<pair<int,int>> q;
        q.push({root,0});
        int ht = 0;

        while(q.size())
        {
            auto pr = q.front();
            q.pop();

            int node = pr.first;
            int ind = pr.second;

            vis.insert(node);

            ht = max(ht,ind);

            for(auto x:adj[node])
            {
                if(vis.count(x))    continue;
                q.push({x,ind+1});
            }
        }
        if(ht == maxx)  ans.push_back(root);
        else if(ht < maxx)
        {
            maxx = ht;
            ans.clear();
            ans.push_back(root);
        }
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        for(int i=0;i<n;i++)
        {
            solve(i,adj);
        }
        return ans;

    }
};