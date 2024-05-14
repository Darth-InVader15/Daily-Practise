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
    bool isVal(int x, int y, vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        
        if(x<0 || y<0 || x>=n || y>= m) return 0;
        return 1;
    }
  public:
    int MinimumEffort(int r, int c, vector<vector<int>> &arr) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dis(r,vector<int>(c,1e9));
        dis[0][0] = 0;
        pq.push({0,{0,0}});
        
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        
        while(!pq.empty())
        {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int dist = pq.top().first;
            pq.pop();
            
            if(x == r-1 && y == c-1)    return dist;
            
            for(int i=0;i<4;i++)
            {
                int tx = x + dx[i];
                int ty = y + dy[i];
                
                if(isVal(tx,ty,arr))
                {
                    int newDist = max(abs(arr[x][y] - arr[tx][ty]),dist);
                    // pq.push({newDist,{tx,ty}});
                    
                    if(newDist < dis[tx][ty])
                    {
                        dis[tx][ty] = newDist;
                        pq.push({newDist,{tx,ty}});
                    }
                
                }
            }
        }
        return dis[r-1][c-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends