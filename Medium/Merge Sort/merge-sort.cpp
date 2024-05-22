//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int arr1[r - l + 1];
        int i = 0,j = l,k = m+1;
        while(j <= m and k <= r){
            if(arr[j] < arr[k]){
                arr1[i++] = arr[j++];
            }
            else arr1[i++] = arr[k++];
        }
        while(j <= m)arr1[i++] = arr[j++];
        while(k <= r)arr1[i++] = arr[k++];
        for(j = 0;j < i;j++)arr[l+j] = arr1[j];
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        // int n = sizeof(arr) / sizeof(arr[0]);
        // if(n == 1)  return;
        if(r<=l)    return;
        
        // cout<<n<<" "<<l<<"- -"<<r<<endl;
        
        int m = (l+r)/2;
        
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends