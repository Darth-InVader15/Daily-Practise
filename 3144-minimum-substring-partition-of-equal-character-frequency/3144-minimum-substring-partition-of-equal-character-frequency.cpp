class Solution {
    bool isBal(vector<int> &arr)
    {
        int temp = -1;
        for(auto x:arr)
        {
            if(temp == -1 && x != 0)    temp = x;
            else if(temp != -1 && x != 0 && x != temp)    return 0;
        }
        return 1;
    }
    int solve(int ind, string s, vector<int> arr, unordered_map<string,int> &mpp)
    {
        if(ind == s.size()) return 0;

        if(mpp.count(s))    return mpp[s];

        int ans = 1e9;
        for(int i=ind;i<s.size();i++)
        {
            // string temp += s[i];
            arr[s[i]-'a']++;

            if(isBal(arr))
            {
                vector<int> temp(26,0);
                ans = min(ans, 1 + solve(0,s.substr(i+1),temp,mpp));
            }
        }

        return mpp[s] = ans;
    }
public:
    int minimumSubstringsInPartition(string s) {
        vector<int> arr(26,0);
        // map<pair<vector<int>,int>,int> mpp;
        unordered_map<string,int> mpp;
        return solve(0,s,arr,mpp);
        
    }
};