//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int l, int r, string &str, vector<vector<int>> &dp)
    {
        if(l>r) return 0;
        
        if(dp[l][r] != -1)  return dp[l][r];
        int take = 1e9, skipl = 1e9, skipr = 1e9;
        if(str[l] == str[r])    take = solve(l+1,r-1,str,dp);
        if(1)
        {
            skipl = 1 + solve(l+1,r,str,dp);
            skipr = 1 + solve(l,r-1,str,dp);
        }
        return dp[l][r] =  min({take,skipl,skipr});
    }
    int kPalindrome(string str, int n, int k)
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int strokes = solve(0,n-1,str,dp);
        
        // cout<<strokes<<"--\n";
        
        return strokes <= k;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends