//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
private:
        // n-> index i->cost or size avail for cutting
    int solve(int price[], int len[], int n, int i, vector<vector<int>> &dp)
    {
        //Base if no size available for cutting, or no rod avail, return 0
        if(i == 0 ||  n == 0)
            return 0;
        
        //Memoization
        if(dp[i][n] != -1)
            return dp[i][n];
        
        // If len index is less than available rod, we can either cut it or not     
        if(len[n-1] <= i)
        {
            // cost of cutting the piece
            int take = price[n-1] + solve(price,len,n,i-len[n-1],dp);
            //
            int dont = solve(price,len,n-1,i,dp);
            
            return dp[i][n] = max(take,dont);
        }
        return dp[i][n] = solve(price,len,n-1,i,dp);
    }
public:
    int cutRod(int price[], int n) {
        int m = n;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int len[n];
        for(int i=0;i<n;i++)
            len[i] = i+1;
        
        return solve(price, len, n, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends