//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    int mod = 1e9 + 7;
    private:
    int solve(int n, vector<int> &dp)
    {
        if(n<2) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        
        
        return dp[n] = (solve(n-1,dp) + solve(n-2,dp))%mod;
    }
  public:
    int firstElement(int n) {
        // basically nth fibo number
        vector<int> dp(n,-1);
        return solve(n-1,dp)%mod;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends