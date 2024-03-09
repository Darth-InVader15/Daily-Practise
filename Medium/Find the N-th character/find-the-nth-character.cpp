//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        string str = "";
        
        for(int i=0;i<s.size();i++)
        {
            string temp = "";
            temp += s[i];
            
            for(int i=0;i<r;i++)
            {
                string str2 = "";
                for(auto x:temp)
                {
                    if(x == '1')    str2 += "10";
                    else str2 += "01";
                }
                temp = str2;
            }
            str += temp;
            
            if(str.size() > n)  break;
        }
        return str[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends