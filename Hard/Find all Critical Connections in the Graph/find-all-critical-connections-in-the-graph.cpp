//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    //tarjan's algorithm
private:
    int timer = 1;
    void dfs(int node, int par, vector<int> adj[], vector<int> &vis, vector<int> &curr, vector<int>&intt, vector<vector<int>> &ans)
    {
        vis[node] = 1;
        curr[node] = timer;
        intt[node] = timer;
        timer++;
        
        for(auto x: adj[node])
        {
            if(x == par)    continue;
            if(!vis[x])
            {
                dfs(x,node,adj,vis,curr,intt,ans);
                intt[node] = min(intt[node],intt[x]);
                
                if(curr[node] < intt[x]) ans.push_back({min(x,node),max(x,node)});
                
            }
            else intt[node] = min(intt[node],curr[x]);
        }
        
    }
public:
	vector<vector<int>>criticalConnections(int n, vector<int> adj[])
	{
	    vector<int> curr(n,0), intt(n,0), vis(n,0);
	    vector<vector<int>> ans;
	    dfs(0,-1,adj,vis,curr,intt,ans);
	    sort(ans.begin(),ans.end());
	    return ans;
	    
	    
	    
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends