class Solution {
private:
    int solve(int i, int j, string str, vector<vector<int>>&dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        //Assuming this is the end of this char
        char ch = str[i];

        int ans = 1 + solve(i+1,j,str,dp);
        //Kinda like MCM, we search for additional ch in the string
        //Then we will partition this string into i+1 - part-1 and part +1 to j
        // This is coz we'll assume that from i to part, ch was printed 
        for(int part = i+1;part<=j;part++)
        {
            if(str[part] == ch)
            {
                //Alt m split kr rhe at part, coz hm yeh assume kar rhe ki i se part tak
                //ch print hua tha.
                int alt = solve(i,part-1,str,dp) + solve(part+1,j,str,dp);
                
                ans = min(ans,alt);
            }
        }
        return dp[i][j] = ans;
    }
public:
    int strangePrinter(string s) {
        //abccbdca
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return solve(0,n-1,s,dp);
    }
};