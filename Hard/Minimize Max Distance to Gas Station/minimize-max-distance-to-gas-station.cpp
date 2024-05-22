//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     double findSmallestMaxDist(vector<int>& stations, int k) {
        int n = stations.size();
        // Define the binary search range
        double low = 0.0;
        double high = *max_element(stations.begin(), stations.end()) - *min_element(stations.begin(), stations.end());
        
        // Binary search on the answer
        while (high - low > 1e-6) {
            double mid = (low + high) / 2.0;
            if (isFeasible(stations, k, mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return round(high * 100) / 100.0; // return rounded to 2 decimal places
    }

private:
    bool isFeasible(vector<int>& stations, int k, double d) {
        int count = 0;
        for (int i = 1; i < stations.size(); i++) {
            int distance = stations[i] - stations[i - 1];
            count += (int)(distance / d);
        }
        return count <= k;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends