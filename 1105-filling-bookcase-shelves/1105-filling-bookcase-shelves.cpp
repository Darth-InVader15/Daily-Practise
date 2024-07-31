class Solution {
    int mcm(int ind,vector<vector<int>> &arr,int tar, vector<int> &dp)
    {
        if(ind == arr.size())   return 0;

        if(dp[ind] != -1)   return dp[ind];

        int width = 0, ht = 0, ans=1e9;
        for(int i=ind;i<arr.size();i++)
        {
            width+=arr[i][0];
            ht = max(ht,arr[i][1]);

            if(width <= tar)
            {
                int anss = ht + mcm(i+1,arr,tar,dp);
                ans = min(ans,anss);
            }
            else break;
        }
        return dp[ind] = ans;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int width) {
        int n = books.size();
        vector<int> dp(n,-1);
        return mcm(0,books,width,dp);
    }
};