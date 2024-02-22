//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    int mod = 1e9 + 7;
    int solve(int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &dp)
    {
        if(ind2 == str2.size()) return 1; // str2 was found
        if(ind1 == str1.size()) return 0; // str1 has ended
        
        if(dp[ind1][ind2]!= -1) return dp[ind1][ind2];
        
        int take = 0, dont = 0;
        
        if(str1[ind1] == str2[ind2])    take = solve(ind1+1,ind2+1,str1,str2,dp);
        dont = solve(ind1+1,ind2,str1,str2,dp);
        
        return dp[ind1][ind2] = (take+dont)%mod;
        
    }
    public:
    int subsequenceCount(string s, string t)
    {
        int n = s.size() + 1;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,0,s,t,dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends