class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        // int cnt=0;
        vector<int> anss;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == x)    anss.push_back(i);
        }
        int cnt = anss.size();
        vector<int> ans(queries.size(),-1);

        for(int i=0;i<queries.size();i++)
        {
            if(queries[i]>anss.size())   continue;
            else ans[i] = anss[queries[i]-1];
        }
        return ans;
        
    }
};