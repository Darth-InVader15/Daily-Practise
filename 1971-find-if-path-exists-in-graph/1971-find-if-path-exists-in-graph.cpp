class Solution {
private:
    bool solve(vector<vector<int>>&adj,int src,int dest)
    {
        queue<int> q;
        unordered_set<int> stt;
        q.push(src);

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            if(curr == dest)    return 1;

            for(auto x: adj[curr])
            {
                if(stt.count(x))    continue;
                stt.insert(x);
                q.push(x);
            }
        }
        return 1 == 0;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        vector<vector<int>> adj(n);

        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        return solve(adj,source,dest);
    }
};