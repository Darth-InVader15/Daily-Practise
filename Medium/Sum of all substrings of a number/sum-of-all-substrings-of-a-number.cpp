//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
          // your code here
        long long sum=0 ,md =1e9+7 ,prev=0;
        for(int i=0;i<s.length();i++)
        {
            int digit=s[i]-'0';
            prev=( (digit*(i+1))%md +prev)%md;
            sum=((sum*10)%md + prev)%md;
        }
        return sum;
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
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends