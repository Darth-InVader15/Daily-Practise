class Solution {

private:
   void f(vector<vector<char>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
           return; 
        }
        if(grid[i][j]=='0'){
            return;
        }
        
        grid[i][j]='0';
        f(grid,i+1,j);
        f(grid,i-1,j);
        f(grid,i,j+1);
        f(grid,i,j-1);

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt =0;
        //vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if(grid[i][j] == '1' )//&& vis[i][j] == 0)
            {
                cnt++;
                f(grid, i,j);//,vis);
            }
        }
    }
      return cnt;      
    }
};