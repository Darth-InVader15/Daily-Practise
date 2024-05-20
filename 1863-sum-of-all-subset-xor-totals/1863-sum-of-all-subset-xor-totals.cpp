class Solution {
    int ans = 0;
    void solve(vector<int> &arr, int ind,int num)
    {
        if(ind == arr.size())
        {
            ans += num;
            return;
        }

        //take
        solve(arr,ind+1,num^arr[ind]);
        //dont
        solve(arr,ind+1,num);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        solve(nums,0,0);
        return ans;
    }
};