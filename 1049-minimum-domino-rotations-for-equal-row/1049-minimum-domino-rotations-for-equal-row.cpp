class Solution {
private:
    int solve(int ind, int curr, vector<int>&top, vector<int> &bot, vector<vector<int>> &dp)
    {
        if(ind == top.size()) return 0;
        //memo
        // if(dp[ind][curr] != -1) return dp[ind][curr];

        int takeTop = 1e9, takeBot = 1e9;

        if(ind == 0)
        {
            takeTop = solve(ind+1,top[0],top,bot,dp);
            takeBot = 1 + solve(ind+1,bot[0],top,bot,dp);
        }
        else
        {
            if(top[ind] == curr)
            {
                takeTop = solve(ind+1,curr,top,bot,dp);
                // cout<<"here\n";
            }

            else if(bot[ind] == curr)
            {
                takeBot = 1 + solve(ind+1,curr,top,bot,dp);
                // cout<<"we go\n";
            }

            // else
            // {
            //     takeTop = 1e9;
            //     takeBot = 1e9;
            // }
        }
        return dp[ind][curr] = min(takeTop,takeBot);
    }
public:
    int minDominoRotations(vector<int>& top, vector<int>& bot) {

        int n = top.size();
        vector<vector<int>> dp(n,vector<int>(7,-1));
        vector<vector<int>> dpp(n,vector<int>(7,-1));

        int ans = min(solve(0,0,top,bot,dp),solve(0,0,bot,top,dpp));

        if(ans >= 1e9) return -1;
        return ans;
        
    }
};