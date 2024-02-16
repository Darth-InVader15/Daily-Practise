//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        queue<int> q;
        q.push(arr[0]);
        int i=1;
        
        while(!q.empty() && i < n)
        {
            int ele = q.front();
            q.pop();
            
            if(arr[i] > ele || (i+1 < n && arr[i+1] > ele))  return 0;
            
            q.push(arr[i]);
            
            if(i+1 < n)
            q.push(arr[i+1]);
            i += 2;
            
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends