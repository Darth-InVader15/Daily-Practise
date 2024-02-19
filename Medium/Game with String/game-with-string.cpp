//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    
public:
    int minValue(string s, int k){
        unordered_map<char, int> mp;
    
        // Count the frequency of each character in the string
        for(auto x : s){
            mp[x]++;
        }
    
        // Create a max heap (priority_queue) based on character frequency
        priority_queue<pair<int, char>> pq;
        for(auto x : mp){
            pq.push({x.second, x.first});
        }
    
        // Perform k operations
        for(int i = 0; i < k; i++){
            if(!pq.empty()){
                pair<int, char> ele = pq.top();
                if(ele.first >= 1){
                    // Decrement the frequency of the most frequent character
                    // and update the heap
                    mp[ele.second]--;
                    pq.pop();
                    pq.push({ele.first - 1, ele.second});
                }
            }
        }
    
        // Calculate the minimum value after k operations
        int ans = 0;
        for(auto x : mp){
            ans += (x.second * x.second);
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends