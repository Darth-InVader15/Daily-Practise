//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool isAdditiveSequence(string s) {
        int len = s.length();
        string temp = "";
        
        int x = 0,y = 0,z = 0,flag = 0;
        
        for(int i = 0; i < len-2;i++)
        {
            x = x*10 + int(s[i]-'0');
            
            for(int j = i+1;j < len-1; j++)
            {
                y = y*10 + int(s[j]-'0');
                
                for(int k = j+1; k < len; k++)
                {
                    z = z*10 + int(s[k]-'0');
                    
                    if(x + y == z){ flag = 1; break;};
                }
                if(flag == 1)break;
                else z = 0;
            }
            if(flag == 1)break;
            else y = 0;
        }
        
        
        if(x + y != z) return 0;
        
        temp = temp + to_string(x);
        temp = temp + to_string(y);
        
        while(temp.length() < len)
        {
            z = x + y;
            temp = temp + to_string(z);
            x = y;
            y = z;
            
        }
        
        if(temp == s) return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends