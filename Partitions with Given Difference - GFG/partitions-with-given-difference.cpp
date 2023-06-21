//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
int mod = 1e9 +7;
    int solve(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(ind == 0 && tar != 0)
        return 0;
        
        if(ind == 0 && tar == 0)
        return 1;
        
        if(dp[ind][tar] != -1)
            return dp[ind][tar];
            
        if(tar >= arr[ind-1])
        {
            int take = solve(ind-1,tar-arr[ind-1],arr,dp)%mod;
            int dont = solve(ind-1,tar,arr,dp)%mod;
            
            return dp[ind][tar] = (take%mod + dont%mod)%mod;
        }
        return dp[ind][tar] = solve(ind-1,tar,arr,dp)%mod;
    }
public:
    int countPartitions(int n, int d, vector<int>& arr) {
        
        //  A-B = d
        //  A+B = sum => A = sum+d / 2
        
        int sum = accumulate(arr.begin(),arr.end(),0);
        if((sum+d) % 2 != 0)
        return 0;
        
        int tar = (sum + d) / 2;
        
        vector<vector<int>> dp(n+1,vector<int>(tar+1,-1));
        return solve(n,tar,arr,dp);
        
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