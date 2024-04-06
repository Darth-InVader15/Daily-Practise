class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lst =-101;
        int i=0;
        for(auto x:nums)
        {
            if(x != lst)
            {
                nums[i]=x;
                i++;
            }
            lst =x;            
        }
        
        return i;

        
    }
};