class DSU{
    vector<int> par;
    public:
    DSU(int n)
    {
        par.resize(n+1);
        for(int i=0;i<=n;i++)   par[i] = i;
    }
    int findPar(int node)
    {
        if(node == par[node])   return node;
        return par[node] = findPar(par[node]);
    }
    bool connect(int u, int v)
    {
        if(findPar(u) == findPar(v))    return 1;
        par[findPar(v)] = u;
        return false;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU ds(n);

        for(auto x:edges)
        {
            int u = x[0], v = x[1];

            if(ds.connect(u,v)) return x;
        }
        return {-1,-1};
    }
};