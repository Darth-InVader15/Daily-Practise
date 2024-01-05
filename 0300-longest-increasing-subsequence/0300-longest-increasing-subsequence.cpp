class Solution {
    int solve(int ind,int prev, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(ind == arr.size()) return 0;
        
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        
        int take = 0, skip = 0;
        if(prev == -1 || arr[prev] < arr[ind])    take = 1 + solve(ind+1,ind,arr,dp);
        
        skip = solve(ind+1,prev,arr,dp);
        
        return dp[ind][prev+1] = max(take,skip);
        
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
        
    }
};