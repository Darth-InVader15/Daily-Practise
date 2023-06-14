//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    private:
    int solve(int x, int y, vector<vector<int>> &dp)
    {
        //base cases
        //Destination arrived
        if(x==0 && y==0)
            return 1;
        
        //Out of bounds
        if(x<0 || y<0)
            return 0;
        
        if(dp[x][y] != -1)
        return dp[x][y];
        
        //For going left and top    
        int lt = solve(x-1,y,dp);
        int up = solve(x,y-1,dp);
        
        
        return dp[x][y]=lt+up;
        
    }
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a,vector<int>(b,-1));
        
        
        return solve(a-1,b-1,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends