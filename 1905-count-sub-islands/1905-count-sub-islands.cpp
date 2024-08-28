class DSU {
    vector<int> par,siz;
    public:
    DSU (int n)
    {
        par.resize(n);
        siz.resize(n,1);

        for(int i=0;i<n;i++)    par[i] = i;
    }

    int findPar(int node)
    {
        if(node == par[node])   return par[node];
        return par[node] = findPar(par[node]);
    }
    void merge(int u,int v)
    {
        int pu = findPar(u), pv = findPar(v);
        if(pu == pv)    return;

        if(siz[pu] > siz[pv])
        {
            par[pv] = pu;
            siz[pu] += siz[pv];
        }
        else
        {
            par[pu] = pv;
            siz[pv] += siz[pu];
        }
    }
};
class Solution {
private:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x,int y,vector<vector<int>> &arr, vector<vector<int>> &vis, DSU* ds)
    {
        if(x>=arr.size() || y>= arr[0].size())  return;
        vis[x][y] = 1;
        int u = (arr[0].size()*x) + y;
        for(int i=0;i<4;i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            int v = (arr[0].size() * tx) + ty; 
            if(tx>=0 && ty >= 0 && tx<arr.size() && ty < arr[0].size())
            {
                if(arr[tx][ty] == 1 && !vis[tx][ty])
                {
                    ds->merge(u,v);
                    dfs(tx,ty,arr,vis,ds);
                }
            }
        }
    }
    // void match(int )
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        DSU* ds1 = new DSU(m*n);
        DSU* ds2 = new DSU(m*n);
        // ds1(m*n);
        // ds2(m*n)
        vector<vector<int>> vis1(m,vector<int>(n,0));
        auto vis2 = vis1;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!grid1[i][j] || vis1[i][j])   continue;
                dfs(i,j,grid1,vis1,ds1);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!grid2[i][j] || vis2[i][j])   continue;
                dfs(i,j,grid2,vis2,ds2);
            }
        }

        unordered_map<int,int> mpp;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!grid2[i][j]) continue;
                int u = (n*i) + j;
                // cout<<ds1->findPar(u)<<" "<<ds2->findPar(u)<<endl;
                if(mpp.find(ds2->findPar(u)) != mpp.end() && mpp[ds2->findPar(u)] != -1)
                {
                    if(mpp[ds2->findPar(u)] != ds1->findPar(u))
                        mpp[ds2->findPar(u)] = -1;
                    else if(grid1[i][j] == 0)   mpp[ds2->findPar(u)] = -1;
                }
                if(mpp.find(ds2->findPar(u)) == mpp.end() && mpp[ds2->findPar(u)] != -1)
                {
                    if (grid1[i][j])    mpp[ds2->findPar(u)] = ds1->findPar(u);
                    else mpp[ds2->findPar(u)] = -1;
                }
            }
        }
        int cnt = 0;
        for(auto x:mpp)
        {
            if(x.second != -1) cnt++;
            cout<<x.first<<" "<<x.second<<endl;
        } 
        
        return cnt;
    }
};