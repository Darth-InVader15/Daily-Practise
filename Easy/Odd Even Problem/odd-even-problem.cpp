//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        unordered_map<char,int>mp;
        for(int i = 0;i < s.size();i++){
            mp[s[i]]++;
        }
        int x = 0,y = 0;
        for(auto it : mp){
            char ch = it.first;
            int freq = it.second;
            if(((ch-'a')+1)%2==0){
                if(freq%2==0){
                    x++;
                }
            }
            else{
                if(freq%2!=0){
                    y++;
                }
            }
        }
        if((x+y)%2==0){
            return "EVEN";
        }
        return "ODD";
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends