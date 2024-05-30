//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int mod = 1e9 + 7;
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(j == s2.size())    return 1;
        if(i == s1.size())  return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int take = 0, dont = 0;
        
        if(s1[i] == s2[j])  take = solve(i+1,j+1,s1,s2,dp)%mod;
        dont = solve(i+1,j,s1,s2,dp)%mod;
        
        return dp[i][j] = (take+dont)%mod;
    }
  public:
    int countWays(string s1, string s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return solve(0,0,s1,s2,dp)%mod;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends