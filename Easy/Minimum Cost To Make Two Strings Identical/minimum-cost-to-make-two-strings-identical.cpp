//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
     public:
  int solve(string &x,string &y,vector<vector<int>>&dp,int i,int j){
      
      if(i>=x.length() || j>=y.length())
      return 0;
      
      if(dp[i][j]!=-1)
      return dp[i][j];
      
      int ans=0;
      if(x[i]==y[j])
      ans=1+solve(x,y,dp,i+1,j+1);
      else{
          ans=max(solve(x,y,dp,i+1,j),solve(x,y,dp,i,j+1));
      }
      return dp[i][j]=ans;
  }
    int findMinCost(string x, string y, int costX, int costY) {
        
        int n=x.length();
        int m=y.length();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        
        int res=solve(x,y,dp,0,0);
         int ans=(n-res)*costX+(m-res)*costY;
         return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends