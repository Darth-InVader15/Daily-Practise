//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        
        //BASE CASES
        //If our arr size is 0 but sum isn't 0, it means that we dont have the subset of given sum
        //If sum is 0, it means that subset is found
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;
            }
        }
        
        for(int ind = 1;ind<n+1;ind++)
        {
            for(int sm = 1;sm<sum+1;sm++)
            {
                //We'll check if the curr sum is <= req sum or not
                //If yes, we have to options, either to take it or not
                //If no, we dont take it
                
                if(arr[ind-1] <=sm)
                {
                    int take = dp[ind-1][sm-arr[ind-1]];
                    int dont = dp[ind-1][sm];
                    
                    dp[ind][sm] = take || dont;
                }
                else
                    dp[ind][sm] = dp[ind-1][sm];
            }
        }
        
        return dp[n][sum];
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