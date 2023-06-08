class Disjointset
{
    vector<int>rank,parent,size;

    public:
    Disjointset(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

        int findUpar(int node){
            if(node == parent[node])
                return node;
            return parent[node] = findUpar(parent[node]);
       /*  */ }

        void unionByRank(int u,int v)
        {
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v)
            return;
             
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u])
            {
                parent[ulp_v] = ulp_u;
            } 
            else
            {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }   
        }
        void unionBySize(int u,int v)
        {
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);

            if(ulp_u == ulp_v)
            return;

            if(size[ulp_u] > size[ulp_v])
            {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            else
            {
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=ulp_u; 
            }
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isC) {
        
        int v = isC.size();
        Disjointset ds(v);
        
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(i == j)
                    continue;
                
                if(isC[i][j])
                {
                    ds.unionByRank(i,j);
                }
            }
        }
        
        int cnt = 0;
        
        for(int i=0;i<v;i++)
        {
            if(ds.findUpar(i) == i)
                cnt++;
        }
        return cnt;
        
    }
};