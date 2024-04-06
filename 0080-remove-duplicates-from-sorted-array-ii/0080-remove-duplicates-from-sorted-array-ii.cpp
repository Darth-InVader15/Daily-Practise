class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mpp, mpp2;
        int cnt = 0;

        for(auto x: nums)
        {
            if(mpp[x] < 2) cnt++;// we only need 2 of each
            mpp[x]++;
        }

        int n = nums.size();
        int strt = 0, k = cnt+1;

        while(strt < nums.size())
        {
            if(mpp2[nums[strt]] >= 2)
            {
                nums.erase(nums.begin() + strt);
                continue;
            }
            mpp2[nums[strt]]++;
            strt++;

        }
        return cnt;
        
    }
};