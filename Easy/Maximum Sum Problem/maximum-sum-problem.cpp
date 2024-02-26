//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        // int ans = 0;
        
        int maxSum(int n)
        {
            if(n<2) return n;
            int b2 = n/2;
            int b3 = n/3;
            int b4 = n/4;
            
            int ans = n;
            
            ans = max(ans, maxSum(b2)+maxSum(b3)+maxSum(b4));
            
            return ans;
            
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends