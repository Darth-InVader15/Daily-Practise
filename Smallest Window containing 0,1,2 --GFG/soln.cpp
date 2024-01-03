//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        vector<int> arr(3);
        int cnt = INT_MAX;
        deque<int> dq;
        
        for(auto x: S)
        {
            int num = x-'0';
            dq.push_back(num);
            arr[num]++;
            
            if(arr[0] > 0 && arr[1] > 0 && arr[2] > 0)
            {
                while(arr[dq.front()] > 1)
                {
                    arr[dq.front()]--;
                    dq.pop_front();
                }
                // while(arr[dq.back()] > 1)   dq.pop_back();
                int n = dq.size();
                cnt = min(n,cnt);
            }
        }
        if(cnt == INT_MAX) return -1;
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends