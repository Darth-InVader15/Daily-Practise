//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    int ans = 0;
    void dfs(int node, int tar, vector<vector<int>> &adj, set<pair<int,int>> &stt,
                unordered_set<int> &nodes)
    {
        // cout<<nodes.size()<<" "<<node<<endl;
        if(node == tar && nodes.size() == adj.size())
        {
            ans = 1;
            return;
        }
        nodes.insert(node);
        
        for(auto x:adj[node])
        {
            // cout<<"n\n";
            if(stt.count({node,x}) || stt.count({x,node}))  continue;
            stt.insert({node,x});
            stt.insert({x,node});
            
            dfs(x,tar,adj,stt,nodes);
            
            // stt.erase({node,x});
            // stt.erase({x,node});
        }
            
    }
public:
	int isPossible(vector<vector<int>>paths){
	    
	    int n = paths.size();
         for(int i=0;i<n;i++)
         {
    	  int sum = accumulate(paths[i].begin(),paths[i].end(),0);
    	  if(sum&1) return 0;
         }
         return 1;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends