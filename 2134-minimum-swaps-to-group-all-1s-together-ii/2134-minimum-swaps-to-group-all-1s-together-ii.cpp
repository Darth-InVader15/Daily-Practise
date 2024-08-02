class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for(auto x:nums)    if(x==1)    cnt++;
        int ones = 0, ans = 1e9;
        for(int i=0;i<cnt;i++)
        {
            if(nums[i] == 1)    ones++;
        }
        int strt = 0;
        ans = min(ans,cnt-ones);
        for(int i=cnt;i<2*n;i++)
        {
            if(strt == n)   break;
            int ind = i%n;
            
            if(nums[strt++] == 1)   ones--;
            if(nums[ind] == 1)    ones++;

            ans = min(ans, cnt-ones);    
        }
        return ans;
    }
};