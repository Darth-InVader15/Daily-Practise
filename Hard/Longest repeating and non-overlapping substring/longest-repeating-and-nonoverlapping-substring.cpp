//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int maxx = 0, endd=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(s[i-1] == s[j-1] && dp[i-1][j-1] < j-i) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
                
                if(maxx < dp[i][j])
                {
                    maxx = dp[i][j];
                    endd = i;
                }
               
            }
        }
        return maxx == 0 ? "-1" : s.substr(endd-maxx,maxx);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends