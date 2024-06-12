class Solution {
public:
    void sortColors(vector<int>& nums) {
        int clr0 =0, clr1=0,clr2=0;

        for(auto x: nums)
        {
            if(x == 0)
            clr0++;
            else if(x == 1)
            clr1++;
            else
            clr2++;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(clr0)
            {
                nums[i] = 0;
                clr0--;
            }
            else if(clr1)
            {
                nums[i] = 1;
                clr1--;
            }
            else
            {
                nums[i] = 2;
            }
        }
        
    }
};