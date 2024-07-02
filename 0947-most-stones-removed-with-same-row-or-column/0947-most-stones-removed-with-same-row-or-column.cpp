class DSU{
    public:
    vector<int> par,siz;
    DSU(int n){
        siz.resize(n,1);
        par.resize(n);

        for(int i=0;i<n;i++)    par[i] = i;
    }
    int findPar(int node)
    {
        if(par[node] == node)   return node;
        return par[node] = findPar(par[node]);
    }

    void connect(int u,int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv)    return;

        if(siz[pu] >= siz[pv])
        {
            par[pv] = pu;
            siz[pu] += siz[pv];
        }
        else
        {
            par[pu] = pv;
            siz[pv] += pu;
        }
        // par[findPar(v)] = findPar(u);
        // return;
    }
    int calc(){
        int cnt = 0;
        for(int i=0;i<par.size();i++)    cnt += (par[i] == i);
        return cnt;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        //divide into provinces or groups
        //cnt from each grp is no of ele -1
        int n = stones.size();
        DSU* ds = new DSU(n);
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                // if(i == j)  continue;
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) 
                    ds->connect(i,j);   
            }
        }
        // unordered_map<int,int> mpp;
        // for(auto x:ds->par)
        // {
        //     // cout<<x<<"--\n";
        //     mpp[x]++;
        // }
        // int ans = 0;
        // for(auto itr:mpp)   ans += (itr.second-1);
        return n - ds->calc();       
        
    }
};