//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int lo = 0, hi = n-1;
        int lower = 0, upper = 1e9;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if(arr[mid] <= k)
            {
                lower = max(lower,arr[mid]);
                lo = mid + 1;
            }
            else if(arr[mid] > k)   hi = mid -1;
        }
        if (lower == k) return k;
        lo = 0, hi = n-1;
        
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            if(arr[mid] >= k)
            {
                upper = min(upper,arr[mid]);
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return abs(lower-k)<abs(abs(upper-k)) ? lower : upper;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends