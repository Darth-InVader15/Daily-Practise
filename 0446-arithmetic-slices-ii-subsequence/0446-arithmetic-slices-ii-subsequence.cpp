class Solution {
public:
    int memo[1024][1024];
    int FindNextSlices(vector<int>& nums, int current, int previous)
    {
        if(current>=nums.size()) return 0;
        if(memo[current][previous]!=-1) return memo[current][previous];
        int cnt=0;
        long long next_target=(long long)nums[current]*2-nums[previous];
        for(int i=current+1; i<nums.size(); i++){
            if(nums[i]==next_target)
                cnt+=(1+FindNextSlices(nums, i, current));
        }
        return memo[current][previous]=cnt;
    }
    int GetArithmeticSlices(vector<int>& nums, int start)
    {
        if(start+2>=nums.size()) return 0;
        int cnt=0;
        for(int i=start+1; i<nums.size()-1; i++)
            cnt+=FindNextSlices(nums, i, start);
        return cnt+GetArithmeticSlices(nums, start+1);
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return GetArithmeticSlices(nums, 0);
    }
};