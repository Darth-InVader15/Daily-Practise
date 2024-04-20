class Solution {
private:
    vector<vector<int>> ans;

    bool isVal(int x, int y, vector<vector<int>> &arr)
    {
        if(x<0 || y<0 || x>= arr[0].size() || y>= arr.size())   return 0;
        return 1;
    }
    void solve(int x, int y,int mx, int my, vector<vector<int>> &arr,vector<int> &anss)
    {
        if(!isVal(x,y,arr) || arr[x][y] != 1)   return;
        arr[x][y] = 2;

        if(x > mx || (x == mx && y>my))
        {
            mx = x;
            my = y;
            anss[2] = my;
            anss[3] = mx;
        }

        solve(x+1,y,mx,my,arr,anss);
        solve(x-1,y,mx,my,arr,anss);
        solve(x,y+1,mx,my,arr,anss);
        solve(x,y-1,mx,my,arr,anss);
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land[0].size();
        int m = land.size();

        for(int k=0;k<m;k++)
        {
            for(int j=0;j<n;j++)
            {
                if(land[k][j] == 1)
                {
                    vector<int> anss(4);
                    anss[0] = k;
                    anss[1] = j;

                    solve(k,j,j,k,land,anss);
                    ans.push_back(anss);
                }
            }
        }
        return ans;
        
    }
};