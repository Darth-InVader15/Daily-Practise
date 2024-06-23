class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int,greater<int>> ms;
        int ans = 0, lt = 0;

        for(int rt = 0;rt<nums.size();rt++)
        {
            ms.insert(nums[rt]);
            int maxx = *ms.begin();
            int minn = *ms.rbegin();

            while(maxx-minn > limit)
            {
                ms.erase(ms.find(nums[lt++]));
                maxx = *ms.begin();
                minn = *ms.rbegin();
            }

            ans = max(ans,1+rt-lt);
        }
        return ans;
    }
};