//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long 
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        
        if(n < 2)
            return 0;
        
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        
        long long tot = 0;
        
        while(!pq.empty())
        {
            long long sum = 0;
            
            sum+=pq.top();
            pq.pop();
            
            sum += pq.top();
            pq.pop();
            
            if(!pq.empty())
            pq.push(sum);
            
            tot+=sum;
        }
        return tot;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends