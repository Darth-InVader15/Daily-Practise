//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n+2,1);
        unordered_map<int,int> mpp;
        
        int maxi = 0;
        int maxx = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i] > arr[j])
                {
                    //If the subseq is larger using this ele
                    if(dp[i] < 1+dp[j])
                    {
                        dp[i] = 1+dp[j]; 
                        mpp[i] = j; 
                    }   
                }
            }
            if(dp[i] > maxx)
            {
                maxi = i;
                maxx = dp[i];
            }
            
        }
        //cout<<maxi<<" ---\n";
        vector<int> ans;
        ans.push_back(arr[maxi]);
        while(mpp.find(maxi) != mpp.end())
        {
            ans.push_back(arr[mpp[maxi]]);
            maxi = mpp[maxi];
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends