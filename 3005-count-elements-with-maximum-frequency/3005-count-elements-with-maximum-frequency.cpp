#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> arr(100,0);

        for(auto x:nums)    arr[x-1]++;
        sort(arr.begin(),arr.end(),greater<int>());
        int maxx = arr[0];
        int ans = arr[0];

        for(int i=1;i<100;i++)
        {
            if(maxx == arr[i])  ans+=arr[i];
            else break;
        }
        return ans;

    }
};