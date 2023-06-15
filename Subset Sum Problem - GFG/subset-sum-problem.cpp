//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
private:
    int recurse(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {
        //Base case
        if(ind == 0 && sum !=0)
            return 0;
        if(sum == 0)
            return 1;
            
        //Memoization    
            if(dp[ind][sum] != -1)
            return dp[ind][sum];
        
        int wt = arr[ind-1];
        
        if(wt<=sum)
        {
            int take = recurse(ind-1,sum-wt,arr,dp);
            int dont = recurse(ind-1,sum,arr,dp);
            
            return dp[ind][sum] = take||dont;
        }
        else
            return dp[ind][sum] = recurse(ind-1,sum,arr,dp);
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1)); 
        
        return recurse(n,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends