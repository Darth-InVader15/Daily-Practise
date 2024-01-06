class Solution {
    vector<int>dy = {-1,-1,-1,0,0,0,1,1,1};
    vector<int>dx = {-1,0,1,-1,0,1,-1,0,1};
    void solve(int x, int y, vector<vector<int>> &img, vector<vector<int>> &res)
    {
        int n = img.size();
        int m = img[0].size();
        int avg = 0, cnt = 0;
        for(int i=0;i<9;i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if(tx<0 || ty <0 || tx>= n || ty>= m)   continue;
            avg += img[tx][ty];
            cnt++;
        }
        avg = floor(avg/cnt);
        res[x][y] = avg;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int n = img.size();
        int m = img[0].size();

        vector<vector<int>> res(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                solve(i,j,img,res);
            }
        }
        return res;
        
    }
};