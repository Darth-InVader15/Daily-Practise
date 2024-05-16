//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    int cnt = 0;
    int solve(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
        // if(adj[node].size() == 0)   return 1;
        vis[node] = 1;
        
        int sum = 1;
        for(auto x:adj[node])
        {
            if(!vis[x])    sum += solve(x,adj,vis);
        }
        if(node != 1 && sum % 2 == 0)   cnt++;
        return sum;
    }
public:
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
	    vector<vector<int>> adj(n+1);
	    vector<int> vis(n+1,0);
	    
	    for(auto x:edges){
	        adj[x[1]].push_back(x[0]);
	        adj[x[0]].push_back(x[1]);
	    }
	    
	    solve(1,adj,vis);
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends