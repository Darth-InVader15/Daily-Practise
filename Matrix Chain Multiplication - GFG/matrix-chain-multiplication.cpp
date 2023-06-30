//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
// private:
//     int solve(int strt, int endd, int arr[], vector<vector<long long>> &dp)
//     {
//         //base
//         if(strt >= endd)
//             return 0;
//         //memo
//         if(dp[strt][endd] != -1)
//             return dp[strt][endd];
        
//         long long mini = 1e9;
        
//         // part is basically we are dividing the arr into 2 parts to compute the individual no of steps and find the min
//         for(int part=strt;part<endd;part++)
//         {
//             //For a arr with dim(a*b) * arr dim(b*c), tot num of steps, or tot multipllications is a*b*c
//             //Thats the first part of our expression
//             //SUppose {40,20,30,10,30} is split into {40,20,30} {10,30} 
//             //Then no of steps for 1st exp is 40*30*30 and then we recurse on that exp for
//             long long ans = 1ll*arr[strt-1] * arr[part] * arr[endd] + solve(strt,part,arr,dp) + solve(part+1,endd,arr,dp);
//             mini = min(mini,ans);
//         }
//         return dp[strt][endd] = mini;
    //}
    
public:
    int matrixMultiplication(int N, int arr[])
    {
        // partitioning dp
        vector<vector<long long>> dp(N+1,vector<long long>(N+1,-1));
        
        // Memo m i jaa rha tha 1 se N-1
        // Toh tab m i -> N-1 se 1
        // Memo m j jaa rha tha N-1 se 1
        // So tab m j -> 1 se N-1, but if j<i, so it will cross the base case of meme, as i<j hona chahie
        // So better to start j from i+1 till N-1
        
        
        //base 
        for(int i=1;i<N;i++)
            dp[i][i] = 0;
            
        for(int i=N-1;i>=1;i--)
        {
            for(int j=i+1;j<=N-1;j++)
            {
                long long mini = 1e9;
                for(int k=i;k<j;k++)
                {
                    long long ans = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini, ans);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N-1];
        
        //as the dimensions of the mtx are arr[i]*arr[i-1], we start from the first ind rather than the 0th ind
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends