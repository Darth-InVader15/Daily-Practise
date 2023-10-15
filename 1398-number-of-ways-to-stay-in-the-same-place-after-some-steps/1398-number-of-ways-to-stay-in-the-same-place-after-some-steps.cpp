#define intt long long
class Solution {
int mod = 1e9 + 7;

private:
    intt solve(intt ind, intt steps, intt n, vector<vector<intt>> &dp)
    {
        if(ind == 0 && steps == 0) return 1;
        if(!steps) return 0;

        if(dp[ind][steps] != -1) return dp[ind][steps];

        intt lt = 0, rt = 0, nope = 0;

        if(ind > 0) lt = solve(ind-1,steps-1,n,dp)%mod;
        if(ind < n-1)   rt = solve(ind+1,steps-1,n,dp)%mod;
        nope = solve(ind,steps-1,n,dp)%mod;

        return dp[ind][steps] = (rt + lt + nope)%mod;
    }
public:
    int numWays(intt steps, intt n) {

        vector<vector<intt>> dp(steps+3,vector<intt>(steps+1,-1));
        return solve(0,steps,n,dp);
        
    }
};