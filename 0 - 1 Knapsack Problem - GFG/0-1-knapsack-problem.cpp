//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> tab(n+1, vector<int>(W+1,-1));
       
       //Base case, if(ind == 0 || wt ==0) return 0
       
       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<W+1;j++)
           {
               if(i==0 || j==0)
               tab[i][j] = 0;
           }
       }
       
       for(int ind=1;ind<n+1;ind++)
       {
           for(int wtt=1;wtt<W+1;wtt++)
           {
               if(wt[ind-1] <= wtt)
               {
                   tab[ind][wtt] = max(val[ind-1]+tab[ind-1][wtt-wt[ind-1]] ,tab[ind-1][wtt]);
               }
               else
                tab[ind][wtt] = tab[ind-1][wtt];    
           }
       }
       
       return tab[n][W];
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends