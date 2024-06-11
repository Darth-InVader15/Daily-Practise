class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int col = n, row = k+1;
        int mod = 1e9+7;
        // unordered_map<int,int> mpp;
        vector<vector<int>> mpp(row,vector<int>(col,-1));
        for(int i=0;i<col;i++)
        {
            // mpp[][0] = 1;
            mpp[0][i] = 1;
        }
        for(int i=0;i<row;i++)  mpp[i][0] = 1;

        for(int i=1;i<row;i++)
        {
            int sum = 1;
            for(int j=1;j<col;j++)
            {
                sum = (sum + mpp[i-1][j])%mod;
                mpp[i][j] = sum%mod;
            }
        }
        return mpp[row-1][col-1];
    }
};