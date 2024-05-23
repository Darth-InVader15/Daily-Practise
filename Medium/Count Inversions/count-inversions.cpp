//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inv = 0;
    void merge(long long arr[],long long l, long long m, long long r)
    {
        auto lt = l, rt = m+1;
        vector<long long> anss;
        
        while(lt<=m && rt <= r)
        {
            if(arr[lt] <= arr[rt])
            {
                anss.push_back(arr[lt++]);
            }
            else
            {
                inv += (1+m-lt);
                anss.push_back(arr[rt++]);
            }
        }
        while(lt<= m)   anss.push_back(arr[lt++]);
        while(rt<= r)   anss.push_back(arr[rt++]);
        
        for(long long i = 0; i<anss.size();i++)
        {
            arr[i+l]    = anss[i];
        }
    }
    void mergeSort(long long arr[], long long l, long long r)
    {
        if(l>= r)   return;
        
        long long m = (l+r)/2;
        
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        mergeSort(arr,0,N-1);
        return inv;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends