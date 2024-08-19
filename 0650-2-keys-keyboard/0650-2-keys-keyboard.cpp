class Solution {
    vector<vector<int>> dp;
    int solve(int n,int curr,int copy)
    {
        if(n == 0)  return 0;
        if(copy > n)    return 1e9;

        if(dp[n][copy] != -1)   return dp[n][copy];
        //either you paste copy amt of chars or curr amt of chars
        //copy is the no of chars last copied, curr is the no of chars on the screen
        int cop=1e9, cur=1e9;
        if(copy>0)  cop = 1 + solve(n-copy,curr+copy,copy);
        cur = 2 + solve(n-curr,curr+curr,curr);

        return dp[n][copy] = min(cur,cop);
    }
public:
    int minSteps(int n) {
        dp.resize(n,vector<int>(n,-1));
        return solve(n-1,1,0);
    }
};