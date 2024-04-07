//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:

    int solve(int idx1, int idx2, int n, int m, int a[], int b[], vector<vector<int>>&dp){
	    if(idx2>=m) return 0;
	    if(idx1>=n && idx2 <m) return INT_MIN;
	    
	    if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
	    
	    int take = (a[idx1]*b[idx2]) + solve(idx1+1, idx2+1, n, m, a, b, dp);
	    
	    int notTake = solve(idx1+1, idx2, n, m, a, b, dp);
	    
	    return dp[idx1][idx2]= max(take, notTake);
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
	    vector<vector<int>> dp(n, vector<int>(m, -1));
		int ans = solve(0, 0, n, m, a, b, dp);
		
		return ans;
	} 
        

};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends