class Solution {
    int solve(int st_i, int en_i, int st_j, int en_j, vector<vector<int>> &grid) {
        int i, j, start_row = 1e9, end_row = -1, start_col = 1e9, end_col = -1, found = 0;
        for(i=st_i;i<=en_i;i++)    for(j=st_j;j<=en_j;j++){
            if(grid[i][j]){
                start_row = min(start_row, i);
                end_row = max(end_row, i);
                start_col = min(start_col, j);
                end_col = max(end_col, j);
                found = 1;
            }
        }
        return found ? ((end_row - start_row + 1) * (end_col - start_col + 1)) : 0;
    }
    int mcm(vector<vector<int>> &arr)
    {
        int ans = 1e9;
        int area1 = 0, area2 = 0, area3 = 0;
        //the partition could be of 6 types

        //type 1
        for(int i=0;i<arr.size()-1;i++)
        {
            area1 = solve(0,i,0,arr[0].size()-1,arr);
            for(int j=0;j<arr[0].size()-1;j++)
            {
                area2 = solve(i+1,arr.size()-1,0,j,arr);
                area3 = solve(i+1,arr.size()-1,j+1,arr[0].size()-1,arr);
                ans = min(ans,(area1+area2+area3));
            }
            
        }
        //type2
        for(int i=0;i<arr.size()-1;i++)
        {
            area3 = solve(i+1,arr.size()-1,0,arr[0].size()-1,arr);
            for(int j=0;j<arr[0].size()-1;j++)
            {
                area1 = solve(0,i,0,j,arr);
                area2 = solve(0,i,j+1,arr[0].size()-1,arr);
                ans = min(ans,(area1+area2+area3));
            }
        }
        //type 3
        for(int i=0;i<arr[0].size()-1;i++)
        {
            area1 = solve(0,arr.size()-1,i+1,arr[0].size()-1,arr);
            for(int j=0;j<arr.size()-1;j++)
            {
                area2 = solve(0,j,0,i,arr);
                area3 = solve(j+1,arr.size()-1,0,i,arr);
                ans = min(ans,(area1+area2+area3));
            }
        }
        //type 4
        for(int i=0;i<arr[0].size()-1;i++)
        {
            area1 = solve(0,arr.size()-1,0,i,arr);
            for(int j=0;j<arr.size()-1;j++)
            {
                area2 = solve(0,j,i+1,arr[0].size()-1,arr);
                area3 = solve(j+1,arr.size()-1,i+1,arr[0].size()-1,arr);
                ans = min(ans,(area1+area2+area3));
            }
        }
        //type5
        for(int i=0;i<arr.size()-2;i++)
        {
            area1 = solve(0,i,0,arr[0].size()-1,arr);
            for(int j=i+1;j<arr.size()-1;j++)
            {
                area2 = solve(i+1,j,0,arr[0].size()-1,arr);
                area3 = solve(j+1,arr.size()-1,0,arr[0].size()-1,arr);
                ans = min(ans,(area1+area2+area3));
            }
        }
        //type6
        for(int i=0;i<arr[0].size()-2;i++)
        {
            area1 = solve(0,arr.size()-1,0,i,arr);
            for(int j=i+1;j<arr[0].size()-1;j++)
            {
                area2 = solve(0,arr.size()-1,i+1,j,arr);
                area3 = solve(0,arr.size()-1,j+1,arr[0].size()-1,arr);
                ans = min(ans,(area1+area2+area3));
            }
        }
        return ans;
    }
public:
    int minimumSum(vector<vector<int>>& grid) {
        //mcm jaisa 2 partition krke 3no mein min rect find krna hai
        int minx = 1e9, miny = 1e9, maxx = -1e9, maxy = -1e9;

        return mcm(grid);
    }
};