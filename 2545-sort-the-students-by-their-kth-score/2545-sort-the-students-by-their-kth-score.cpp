class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        int m = score[0].size();
        vector<pair<int,int>> arr(n);

        for(int i=0;i<n;i++)
        {
            arr.push_back({score[i][k],i});
        }
        sort(arr.begin(),arr.end(),greater<pair<int,int>>());
        vector<vector<int>> ans(n,vector<int>(m));

        for(int i=0;i<n;i++)
        {
            int x = arr[i].second;
            for(int j=0;j<m;j++)
            {
                ans[i][j] = score[x][j];
            }
        }
        return ans;
    }
};