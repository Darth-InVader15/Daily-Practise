class Solution {
private:
    vector<int> ans;
    bool poss(int x, int y, int n, int m)
    {
        if(x < 0 || y < 0 || x >= n || y >= m)  return 0;
        return 1;
    }
    void dfs(int x, int y,int dir,int a, vector<vector<int>> &arr, set<pair<int,int>> &vis)
    {
        int n = arr.size();
        int m = arr[0].size();
        if(ans.size() == n*m)   return;

        if(dir == 0) // we go right
        {
            while(poss(x,y,n,m) && !vis.count({x,y}))
            {
                ans.push_back(arr[x][y]);
                vis.insert({x,y});
                y++;
            }
            // cout<<x<<" "<<y<<" "<<poss(x,y,n,m)<<" - "<<n<<endl;
            dfs(x+1,y-1,1,n,arr,vis);
        }
        else if(dir == 1) // way down we go
        {
            while(poss(x,y,n,m) && !vis.count({x,y}))
            {
                ans.push_back(arr[x][y]);
                vis.insert({x,y});
                x++;
            }
            dfs(x-1,y-1,2,n,arr,vis);
        }
        else if(dir == 2) // back off <--
        {
            while(poss(x,y,n,m) && !vis.count({x,y}))
            {
                ans.push_back(arr[x][y]);
                vis.insert({x,y});
                y--;
            }
            dfs(x-1,y+1,3,n,arr,vis);
        }
        else if(dir == 3)   //up and up
        {
            // cout<<"--\n";
            while(poss(x,y,n,m) && !vis.count({x,y}))
            {
                ans.push_back(arr[x][y]);
                vis.insert({x,y});
                x--;
            }
            dfs(x+1,y+1,0,n,arr,vis);
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        set<pair<int,int>> vis;
        int r = matrix.size();
        int c = matrix[0].size();
        dfs(0,0,0,r,matrix,vis);
        return ans;
        
    }
};