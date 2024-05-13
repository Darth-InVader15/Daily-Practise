class Solution {
    int solve(int ind, vector<int> &arr,int k,int a, vector<vector<int>> &dp) 
    {
        if(ind >= arr.size())   return 0;

        if(dp[ind][a] != -1)    return dp[ind][a];

        int skip =-1e9, take = -1e9;
        if(!a && ind < arr.size()-1)  skip = solve(ind+1,arr,k,a,dp);
        take = arr[ind] + solve(ind+k,arr,k,1,dp);

        return dp[ind][a] = max(take,skip);
    }
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<vector<int>> dp(energy.size()+1,vector<int>(2,-1));
        return solve(0,energy,k,0,dp);
        
    }
};