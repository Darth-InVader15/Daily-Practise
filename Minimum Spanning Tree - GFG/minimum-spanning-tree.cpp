//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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

        int findUpar(int node)
        {
            if(node == parent[node])
                return node;
                
            return parent[node] = findUpar(parent[node]);
        }

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




class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Kruskal's Algo
        
        vector<pair<int,pair<int,int>>> arr;
        int sum =0;
        
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
            {
                int wt = x[1];
                int src = i;
                int to = x[0];
            
                arr.push_back({wt,{src,to}});
            }
        }
            sort(arr.begin(),arr.end());
        
        
        Disjointset ds(V);
        
        for(auto x: arr)
        {
            int wt = x.first;
            int node = x.second.first;
            int adjnode = x.second.second;
            
            if(ds.findUpar(node) != ds.findUpar(adjnode))
            {
                sum+=wt;
                ds.unionBySize(node,adjnode);
            }
        }
        return sum;
        
    }
    
    
    
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends