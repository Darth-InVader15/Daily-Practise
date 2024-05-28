//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
    int solve(int i,int w,vector<int> &arr, vector<vector<int>> &dp)
    {
        if(w==0)    return 0;
        if(w<0 || i == arr.size()) return 1e9;
        
        if(dp[i][w] != -1)  return dp[i][w];
        
        int take = 1e9, dont = 1e9;
        
        if(arr[i] != -1)   take = arr[i] + solve(i,w-(i+1),arr,dp);
        dont = solve(i+1,w,arr,dp);
        
        return dp[i][w] = min(take,dont);
    }
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<vector<int>> dp(n,vector<int>(w+1,-1));
        int ans = solve(0,w,cost, dp);
        
        return ans >= 1e9 ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends