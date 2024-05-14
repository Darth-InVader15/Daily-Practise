class Solution {
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {-1,1,0,0};
    int isVal(int x, int y, vector<vector<int>> &arr)
    {
        // return 0;
        int n = arr.size();
        int m = arr[0].size();

        if(x < 0 || y < 0 || x>= n || y >= m || arr[x][y]==0)   return 0;
        return 1;
    }
    int solve(int x, int y, vector<vector<int>> &arr, vector<vector<int>> &vis)
    {
        int ans = 0;
        // if(vis[x][y])   return 0;
        // vis[x][y] = 1;
        for(int i=0;i<4;i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if(isVal(tx,ty,arr) && !vis[tx][ty])
            {
                vis[tx][ty] = 1;
                ans = max(ans,arr[tx][ty] + solve(tx,ty,arr,vis));
                vis[tx][ty] = 0;
            }
        }
        return ans;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0) continue;
                vector<vector<int>> vis(n,vector<int>(m,0));
                vis[i][j] = 1;
                ans = max(ans,grid[i][j] + solve(i,j,grid,vis));
                vis[i][j] = 0;
            }
        }
        return ans;
        
    }
};