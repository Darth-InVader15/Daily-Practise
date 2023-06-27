//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // Binary Search approach
       
       // Here we maintain a temp array which is LIS and traverse the a[] arr
       // If we find any ele greater than the temp.last, we insert that to the last
       // Else we find the lowerbound of the ele and replace it with the ele
       // This way we dont get the LIS but the arr we end up with has the same size as the LIS
       // This is because we are only incrementing if the ele is greater than the greatest of temp
       // Else we are just replacing so the size is that of the LIS
       vector<int> temp;
       temp.push_back(a[0]);
       int k=0;
       
       for(int i=1;i<n;i++)
       {
           if(a[i] > temp[k])
           {
               temp.push_back(a[i]);
               k++;
           }
           //Else we will find the lowerbound of a[i] in temp
           else
           {
               int lo = 0;
               int hi = k;
               
               while(lo<=hi)
               {
                    int mid = lo + (hi-lo)/2;
                    if(temp[mid] >= a[i] && temp[mid-1] <a[i])
                    {
                        temp[mid] = a[i];
                        break;
                    }
                    else if(temp[mid] > a[i])
                        hi = mid-1;
                    else
                        lo = mid+1;
               }
           }
       }
       return temp.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends