//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
struct custom
{
    bool operator() (string str1, string str2)
    {  
        return (str1.size() < str2.size());
    } 
};
private:
    int compare(string str1, string str2)
    {
        //Their size diff should be 1
        if(str1.size() - str2.size() != 1)
            return 0;

        int i =0,j=0;

        while(i < str1.size())
        {
            if(str1[i] != str2[j])
                i++;
            else
            {
                i++;
                j++;
            }
        }
        return (j == str2.size());
    }
public:
    int longestChain(int N, vector<string>& arr) {
        int n = arr.size();
        int maxx = 1;

        sort(arr.begin(),arr.end(), custom());
        vector<int> dp(n+1,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(compare(arr[i], arr[j]))
                {
                    if(dp[i] < dp[j]+1)
                    {
                        dp[i] = 1+ dp[j];
                    }
                }
            }
            maxx = max(dp[i],maxx);
        }

        return maxx;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends