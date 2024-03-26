class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(-1);

        for(int i=0;i<=n;i++)
        {
            while(nums[i]>0 && nums[i] <= n && nums[i] != nums[nums[i]])
            {
                cout<<nums[i]<<" -- "<<nums[nums[i]]<<"\n";
                swap(nums[i],nums[nums[i]]);
            }
        }
        for(int i=1;i<=n;i++)    if(i != nums[i])   return i;
        return n+1;
    }
};