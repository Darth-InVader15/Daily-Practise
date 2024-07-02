class Solution {
    int dp[50][50][50];
    int solve(int x1,int y1, int x2, vector<vector<int>> &arr)
    {
        int y2 = (x1+y1) - x2; //as they will be equidistant from origin at any given time
        if(max(x1,y1)>= arr.size() || max(x2,y2)>= arr.size())
            return -1e9;
        if(arr[x1][y1] == -1 || arr[x2][y2] == -1)  return -1e9;

        if(dp[x1][y1][x2] != -1)    return dp[x1][y1][x2];

        if(x1 == arr.size()-1 && y1 == arr.size()-1)    return arr[x1][y1];

        // they can move R-R, R-B, B-B, B-R
        int rr = -1e9, rb = -1e9, bb = -1e9, br = -1e9;
        
        int cnt = arr[x1][y1];
        if(x1 != x2)    cnt += arr[x2][y2];

        rr = solve(x1,y1+1,x2,arr);
        rb = solve(x1,y1+1,x2+1,arr);
        br = solve(x1+1,y1,x2,arr);
        bb = solve(x1+1,y1,x2+1,arr);

        return dp[x1][y1][x2] =  (cnt + max({rr,rb,bb,br}));    

        
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        //so instead of 1 person going to end and coming back
        //we make 2 people going from 0 to end
        memset(dp,-1,sizeof(dp));
        return max(0,solve(0,0,0,grid));
    }
};