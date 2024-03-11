class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> arr(26,0);
        for(auto x:s)   arr[x-'a']++;

        string ans="";
        for(auto x:order)
        {
            while(--arr[x-'a'] >= 0)   ans += x;
        }
        for(auto x:s)
        {
            while(--arr[x-'a'] >= 0)    ans += x;
        }
        return ans;
    }
};