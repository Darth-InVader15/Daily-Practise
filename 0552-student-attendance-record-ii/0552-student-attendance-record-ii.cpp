class Solution {
    int mod = 1e9 + 7;
    long long solve(int i, int absent, int late, vector<vector<vector<long long>>> &dp)
    {
        if (i==0) return 1;
        if (dp[i][absent][late]!=-1) return dp[i][absent][late];

        long long ans=solve(i-1, absent, 0,dp);// P
        ans+=(late<2?solve(i-1, absent, late+1,dp):0);// L
        ans+=(absent==0?solve(i-1, absent+1, 0,dp):0);// A
       
        return dp[i][absent][late]=ans%mod;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(2,vector<long long>(3,-1)));
        return solve(n,0,0,dp);
    }
};