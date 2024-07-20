class Solution {
    void solve(vector<vector<int>> &arr,vector<int> &row,vector<int> &col, int r, int c)
    {
        int sel = min(row[r],col[c]);
        arr[r][c] = sel;
        row[r] -= sel;
        col[c] -= sel;

        if(r == 0 && c==0)  return;
        else if(!row[r])    solve(arr,row,col,r-1,c);
        else solve(arr,row,col,r,c-1);
    }
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> arr(rowSum.size(),vector<int>(colSum.size(),0));
        solve(arr,rowSum, colSum,rowSum.size()-1,colSum.size()-1);

        return arr;
    }
};