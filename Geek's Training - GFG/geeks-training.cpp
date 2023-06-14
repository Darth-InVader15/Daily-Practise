//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    int solve(int day, int last, vector<vector<int>> &pts, vector<vector<int>> &dp)
    {
        //Base case for 0th day
        if(day == 0)
        {
            int maxx = 0;
            for(int i=0;i<3;i++)
            {
                if(i == last)
                continue;
                
                maxx = max(maxx,pts[0][i]);
            }    
            return maxx;
        }
        
        //Dp chck
        
        if(dp[day][last] != -1)
        return dp[day][last];
        
        int maxx = 0;
        //Recursing over the possible dirn of traversals
        for(int i=0;i<3;i++)
        {
            if(i == last)
            continue;
            
            int pt = pts[day][i] + solve(day-1,i,pts,dp);
            maxx = max(maxx, pt);
        }
        return dp[day][last] = maxx;
    }
public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n,vector<int>(4,-1));
        
        return solve(n-1,3,points,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends