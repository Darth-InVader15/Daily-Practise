//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    vector<string> ans;
    void solve(int n, string &anss,int cnt1, int cnt2,unordered_set<string> &vis)
    {
        if(!n)
        {
            if(!vis.count(anss))    ans.push_back(anss);
            return;
        }
        
        anss += '1';
        solve(n-1,anss,cnt1+1,cnt2,vis);
        anss.pop_back();
        if(cnt1>cnt2)
        {
            anss += '0';
            solve(n-1,anss,cnt1,cnt2+1,vis);
            anss.pop_back();
        }
        
    }
public:	
	vector<string> NBitBinary(int n)
	{
	    string anss = "";
	    unordered_set<string> vis;
	    solve(n,anss,0,0,vis);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends