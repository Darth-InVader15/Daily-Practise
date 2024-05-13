class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        ans+=n*(1<<(m-1-0));
        for(int j=1;j<m;j++){
            int col=0;
            for(int i=0;i<n;i++){
              col+= grid[i][0]==0?grid[i][j]^1:grid[i][j];
              
            }
            if(col< n-col) ans+=(n-col)*(1<<(m-1-j));
            else ans+=col*(1<<(m-1-j));         
        }
        return ans;
    }
};