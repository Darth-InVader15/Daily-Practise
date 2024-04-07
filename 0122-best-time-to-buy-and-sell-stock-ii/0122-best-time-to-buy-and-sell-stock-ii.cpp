class Solution {
private:
    int solve(int ind, int buy, vector<int>&price, vector<vector<int>> &dp)
    {
        //base
        if(ind >= price.size())
            return 0;
        //Memo
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        //At each index, we'll check if buy is 1 or 0
        if(buy)
        {
            //buy = 1 = we have to sell this time, we can either wait or sell
            // if(price[ind] > cp)
            // {
               
                int sell = price[ind] + solve(ind+1,0,price,dp);
                int skip = solve(ind+1,1,price,dp);

                return dp[ind][1] = max(skip,sell);
            // }
            // return dp[ind][1] = solve(ind+1,1,cp,price,dp);
        }
        else
        {
            //If we buy, we'll either buy this or we'll skip
            int buy = solve(ind+1,1,price,dp) - price[ind];
            int skip = solve(ind+1,0,price,dp);

            return dp[ind][0] = max(buy,skip);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,0,prices,dp);
        
    }
};