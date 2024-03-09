//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(auto x: edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        // priority_queue<pair<int,pair<int,int>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> pq;
        // pq.push({0,1,0});
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});
        
        vector<pair<int,int>> prev(n+1,{-1,1e9});
        int anss = -1;
        
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node == n && anss == -1)    anss = dist;
            
            for(auto x:adj[node])
            {
                int ndist = dist + x.second;
                if(prev[x.first].first == -1 || ndist < prev[x.first].second )
                {
                    prev[x.first] = {node,ndist};
                    pq.push({ndist, x.first});
                }
            }
            
        }
        
        vector<int> ans;
        int curr = n;
        ans.push_back(anss);
        while(prev[curr].first != -1)
        {
            // cout<<curr<<"-\n";
            ans.push_back(curr);
            if(curr == 1) break;
            
            curr = prev[curr].first;
        }
        if(ans.size() > 1)
        {
            ans.push_back(1);
            reverse(ans.begin()+1,ans.end());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int,int>,int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0],edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1],edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans=0;
        for(int i=2;i<res.size();i++)
        {
            ans+=mp[{res[i],res[i-1]}];
        }
        if(res.size()==1) ans=res[0];
        cout<<ans<<endl;
    }
}

// } Driver Code Ends