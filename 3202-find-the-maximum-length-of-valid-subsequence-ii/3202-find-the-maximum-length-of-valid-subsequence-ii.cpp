class Solution {
    int t;
    int solve(int i,vector<int> &arr,vector<vector<int>> &dp,int tar)
    {
        if(dp[i][tar] != -1)    return dp[i][tar];

        int anss = 1;
        for(int j=i+1;j<arr.size();j++)
        {
            if((arr[i]+arr[j])%t == tar){
                anss += solve(j,arr,dp,tar);
                break;
            }
        }
        return dp[i][tar] = anss;

    }
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        t = k;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int tar = (nums[i]+nums[j])%k;
                ans = max(ans,1+solve(j,nums,dp,tar));
            }
        }
        return ans;
    }
};