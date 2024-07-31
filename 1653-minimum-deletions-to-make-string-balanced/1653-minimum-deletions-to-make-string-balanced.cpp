class Solution {
    vector<vector<int>> dp;
    int solve(int ind,int b,string &str)
    {
        if(ind == str.size())   return 0;

        if(dp[ind][b] != -1)    return dp[ind][b];
        //if b is set, we cant take any a's
        int take = 1e9, dont = 1e9;
        if(b)
        {
            if(str[ind] == 'b') take = solve(ind+1,b,str);
            else dont = 1 + solve(ind+1,b,str);
        }
        else
        {
            if(str[ind] == 'b')
            {
                take = solve(ind+1,1,str);
                dont = 1 + solve(ind+1,0,str); //b is removed
            }
            else take = solve(ind+1,b,str); //a hai to lelo
        }
        return dp[ind][b] = min(take,dont);
    }
public:
    int minimumDeletions(string s) {
        int n = s.size();
        dp.resize(n,vector<int>(2,-1));
        return solve(0,0,s);
    }
};