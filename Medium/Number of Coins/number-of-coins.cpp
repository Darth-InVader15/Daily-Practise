//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    int solve(int ind, vector<int> &arr, int k, vector<vector<int>> &dp)
    {
        if(k == 0)  return 0;
        if(ind == arr.size())   return 1e9;
        
        if(dp[ind][k] != -1)    return dp[ind][k];
        
        int take = 1e9, dont = 1e9, skip = 1e9;
        
        if(arr[ind] <= k)
        {
            take = 1 + solve(ind,arr,k-arr[ind],dp);
            dont = 1 + solve(ind+1,arr,k-arr[ind],dp);
        }
        skip = solve(ind+1,arr,k,dp);
        
        return dp[ind][k] = min({take,dont,skip});
    }
	public:
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    vector<vector<int>> dp(M+1,vector<int>(V+1,-1));
	    int ans = solve(0,coins,V,dp);
	    
	    return ans >= 1e9 ? -1 : ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends