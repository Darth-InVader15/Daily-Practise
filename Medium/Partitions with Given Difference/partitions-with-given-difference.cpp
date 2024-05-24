//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution {
    
    int MOD = 1e9 + 7;
    int solve(int ind, int s1, int s2, vector<int> &arr, int d,vector<vector<int>> &dp)
    {
        if(ind == arr.size())
        {
            if(s1 - s2  == d)   return 1;
            return 0;
        }
        
        if(dp[ind][s1] != -1)   return dp[ind][s1];
        
        int take1 = 0, take2 = 0;
        
        take1 = solve(ind+1,s1+arr[ind],s2,arr,d,dp);
        take2 = solve(ind+1,s1,s2+arr[ind],arr,d,dp);
        
        return dp[ind][s1] = (take1%MOD+take2%MOD)%MOD;
    }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum = accumulate(arr.begin(),arr.end(),0);
        int mod = 1e9 + 7;
        
        if (sum < d || (sum - d) % 2 != 0) return 0;
        
        // Calculate the required subset sum
        int req = (sum - d) / 2;
        
        // Initialize DP table
        vector<vector<int>> dp(n+1, vector<int>(req+1, 0));
        dp[n][0] = 1;  // Base case: there's one way to get sum 0 with no elements
        
        // Populate the DP table
        for (int idx = n-1; idx >= 0; --idx) {
            for (int tar = 0; tar <= req; ++tar) {
                ll notpick = dp[idx+1][tar] % mod;
                ll pick = (tar >= arr[idx]) ? dp[idx+1][tar-arr[idx]] % mod : 0;
                
                dp[idx][tar] = (pick + notpick) % mod;
            }
        }
        
        return dp[0][req];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends