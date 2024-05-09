class Solution {
public:
    
    //pretty much the idea is we have to draw L and its rotation
    //we can be broken down into (no of 1s in col -1)*(no of 1s in row - 1)
    //Honestly, I was using pref and suff and what not which was essentially the same idea
    //but would def give TLE
    //this is a good implementation


    #define ll long long
    
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<int>> top_pre(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++) top_pre[i][j] += (i>0 ? top_pre[i-1][j]:0) + grid[i][j];
        }
        
        vector<vector<int>> bottom_pre(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            for(int i=n-1;i>=0;i--) bottom_pre[i][j] += (i<n-1 ? bottom_pre[i+1][j]:0) + grid[i][j];
        }
        
        vector<vector<int>> left_pre(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) left_pre[i][j] += (j>0 ? left_pre[i][j-1]:0) + grid[i][j];
        }
        
        vector<vector<int>> right_pre(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--) right_pre[i][j] += (j<m-1 ? right_pre[i][j+1]:0) + grid[i][j];
        }
        
        ll int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) continue;
                
                int c1 = max(0, (bottom_pre[i][j]-1)*(left_pre[i][j]-1));
                    
                int c2 = max(0, (bottom_pre[i][j]-1)*(right_pre[i][j]-1));

                int c3 = max(0, (top_pre[i][j]-1)*(left_pre[i][j]-1));

                int c4 = max(0, (top_pre[i][j]-1)*(right_pre[i][j]-1));

                ans += (c1+c2+c3+c4);
            }
        }
        
        return ans;
    }
};