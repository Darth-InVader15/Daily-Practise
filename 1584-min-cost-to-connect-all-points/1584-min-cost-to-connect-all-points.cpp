#define pii tuple<int,int,int>
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        //basically we have to connect all the points with min amt
        // n nodes k liye atleast n-1 edges chahiye
        // and it will make a spanning tree, we have to find the Min Spanning Tree MST
        // We will be using Prim's algo
        int n = pts.size();
        vector<int> vis(n);
        int ans = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        // pii -> int,int int --> dist,node,par

        pq.push({0,0,-1});

        while(pq.size())
        {
            int node = get<1>(pq.top());
            int par = get<2>(pq.top());
            int curr = get<0>(pq.top());
            pq.pop();

            if(vis[node])   continue;
            vis[node] = 1;

            ans += curr;
            int nx = pts[node][0], ny = pts[node][1];
            for(int i=0;i<n;i++)
            {
                if(i == node)   continue;
                auto x = pts[i];
                int dist = abs(x[0]-nx) + abs(x[1]-ny); //manhattan dist
                pq.push({dist,i,node});
            }
        }
        return ans;

    }
};