//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    void dfs (vector<vector<int>>& adj, int i, vector<int>&vis, vector<int>&temp)
    {
        temp.push_back(i);
        vis[i]++;
        
        for (auto it:adj[i])
        {
            if (!vis[it])
                dfs(adj,it,vis,temp);
        }
    }
    
     int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) 
    {
        vector<int>vis(v+1,0);
        
        vector<vector<int>> adj(v+1);
        
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int ans = 0;
        for (int i=1; i<=v; i++)
        {
            if (!vis[i])
            {
                vector <int> temp;
                dfs(adj,i,vis, temp);
                
                bool flag = false;
                
                for (int i=0; i<temp.size(); i++)
                {
                    if (adj[temp[i]].size()<temp.size()-1)
                    {
                        flag = true;
                        break;
                    }
                }
                
                if (flag==false)
                    ans++;
            }
        }
        
        return ans;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends