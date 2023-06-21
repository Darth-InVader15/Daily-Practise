//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int mod = 1e9 + 7;
    int recurse(int ind, int sum,int arr[],vector<vector<int>> &dp)
    {
        //Base Cases
        if(ind == 0 && sum != 0)
        return 0;
        if(sum == 0 && ind == 0)
        return 1;
        //Memoization
        if(dp[ind][sum] != -1)
        return dp[ind][sum];
        
        if(sum >= arr[ind-1])
        {
            //We either take it or we dont
            long long take = recurse(ind-1,sum-arr[ind-1],arr,dp)%mod;
            long long dont = recurse(ind-1,sum,arr,dp)%mod;
            
            return dp[ind][sum] = (take%mod + dont%mod)%mod;
        }
        else
        return dp[ind][sum] = recurse(ind-1,sum,arr,dp)%mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	    return recurse(n,sum,arr,dp);
	   // return dp[n][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends