//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // maybe the for each index from 1 to n-1
        // we store the max ht 1 ele before and 1 ele after the ele
        // our ans would be the min of the two
        
        vector<int> pre(n), post(n);
        int maxx = arr[0];
        pre[0] = arr[0];
        
        for(int i=1;i<n;i++)
        {
            pre[i] = maxx;
            maxx = max(maxx,arr[i]);
        }
        maxx = arr[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            post[i] = maxx;
            maxx = max(maxx,arr[i]);
        }
        long long ans = 0;
        
        for(int i=1;i<n-1;i++)
        {
            ans += max(min(pre[i],post[i]) - arr[i], 0);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends