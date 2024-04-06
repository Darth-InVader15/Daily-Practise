class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int n = nums.size();

        for(auto x:nums)    if(x == val) k++;

        int strt = 0;
        int tar = n-k;
       while(strt < tar)
       {
            // cout<<strt<<" - \n";
            if(nums[strt] == val)
            {
                // while(nums[k] == val)   k++;
                swap(nums[strt],nums[n-k]);
                k--;
                continue;
            }
            strt++;
       }
       return tar;
    }
};