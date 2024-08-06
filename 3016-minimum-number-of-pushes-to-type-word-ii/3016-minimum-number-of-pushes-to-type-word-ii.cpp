class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26);

        for(auto x:word)    arr[x-'a']++;
        sort(arr.begin(),arr.end(),greater<int>());

        int ans = 0;

        for(int i=0;i<26;i++)
        {
            if(arr[i] == 0) break;
            int t = (i/8) + 1;
            ans += (t*arr[i]);
        }
        return ans;
    }
};