class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        double ans = 1e9;
        int lt = 0 , rt = nums.size()-1;

        while(lt<rt)
        {
            double anss = (double)(nums[lt++]+nums[rt--])/2;
            ans = (double)min(ans,anss);
        }
        return ans;
    }

};