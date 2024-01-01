//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // la la la
        int re = 0, mis = 0;
        unordered_set<int> stt;
        
        for(auto x: arr)
        {
            if(!stt.count(x))   stt.insert(x);
            else re = x;
        }
        for(int i=1;i<=n;i++)
        {
            if(!stt.count(i))
            {
                mis=i;
                break;
            }
        }
        
        return {re,mis};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends