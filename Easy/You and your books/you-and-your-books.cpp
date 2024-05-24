//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
//#include<Windows.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        // auto len = arr.length();
        int len = sizeof(arr) / sizeof(arr[0]);
        
        int i=0;
        long long ans = 0;
        long long anss = 0;
        
        while(i<n)
        {   
            if(arr[i] > k)
            {
                ans = max(ans,anss);
                anss = 0;
            }
            else anss += arr[i];
            
            i++;
        }
        ans = max(ans,anss);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends