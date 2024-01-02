class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> arr(201,0);
        int n = 0;

        for(auto x:nums)
        {
            arr[x]++;
            n = max(n,arr[x]);
        }

        vector<vector<int>> ans(n);

        for(int j=0;j<n;j++)
        {
            vector<int> anss;
            for(int i=0;i<201;i++)
            {
                if(arr[i] > 0)  
                {
                    anss.push_back(i);
                    arr[i]--;
                }
            }
            ans[j] = anss;
        }
        return ans;
        
    }
};