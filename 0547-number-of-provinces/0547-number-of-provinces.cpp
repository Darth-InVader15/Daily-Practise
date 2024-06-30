class Solution {
private:
    void dfs(int node,vector<vector<int>> &adj, vector<int> &vis)
    {
        queue<int> q;
        q.push(node);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            if(vis[node])   continue;
            vis[node] = 1;

            for(auto x:adj[node])
            {
                if(!vis[x]) q.push(x);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == j)  continue;
                if(mat[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};