class Solution {
public:
    int firstUniqChar(string s) {
        // unordered_map<int,int> mpp;
        vector<int> arr(26,1e9);
        int n = s.size();

        for(int i=0;i<n;i++)
        {
            if(arr[s[i] - 'a'] != 1e9)   arr[s[i] - 'a'] = 1e6;
            else arr[s[i] - 'a'] = i;
        }
        int ans = 1e6;
        for(auto x:arr)
        {
            // cout<<x<<" ";
            ans = min(ans,x);
        }
        return ans == 1e6 ? -1 : ans;
        
    }
};