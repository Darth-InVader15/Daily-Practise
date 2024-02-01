class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort (nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<vector<int>> temp;
        int s = 0;

        for(int i=0;i<n;i+=3)
        {
            vector<int> anss(3);
            int lt = nums[i] + k;
            if(nums[i+1] > lt || nums[i+2] > lt)
            {
                s=1;
                break;
            }
            anss[0] = nums[i];
            anss[1] = nums[i+1];
            anss[2] = nums[i+2];
            ans.push_back(anss);
        }
        if(s)   return temp;
        return ans;
    }
};