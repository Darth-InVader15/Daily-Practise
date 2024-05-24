class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            int anss = nums[i];
            int cnt = 1;
            for(int j=i+1;j<n;j++)
            {
                anss |= nums[j];
                cnt++;
                if(anss >= k)   break;
            }
            if(anss >= k)   ans = min(ans,cnt);

        }
        return ans==INT_MAX ? -1 : ans;
    }
};