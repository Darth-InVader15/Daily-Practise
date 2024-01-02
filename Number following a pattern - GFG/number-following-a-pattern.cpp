//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        // if DDDDII 5432167
        stack<int> stk;
       string ans="";
       int n=s.length();
        int count=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='D')
            {
                stk.push(count);
                count++;
                
            }
            else if(s[i]=='I')
            {
                stk.push(count);
                count++;
                while(!stk.empty())
                {
                  ans=ans+to_string(stk.top());
                  stk.pop();
                }
            }
        }
        stk.push(count);
        while(!stk.empty())
        {
            ans=ans+to_string(stk.top());
            stk.pop();
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends