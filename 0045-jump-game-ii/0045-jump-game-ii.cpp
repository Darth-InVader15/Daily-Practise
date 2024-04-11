class Solution {
    //----------------DP--------------------
// private:
//     int solve(int ind, vector<int> &arr, vector<int> &dp)
//     {
//         if(ind >= arr.size())
//             return 1e9;
//         if(ind == arr.size()-1)
//             return 0;
        
//         if(dp[ind] != -1)
//             return dp[ind];
        
//         int cnt = 1e9;

//         for(int i=1;i<=arr[ind];i++)
//         {
//             int steps = 1 + solve(ind+i,arr,dp);

//             cnt = min(cnt,steps);
//         }
//         return dp[ind] = cnt;
//     }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        for(int i=1;i<n;i++)
        {
            nums[i] = max(i+nums[i],nums[i-1]);
        }
        int curr = 0, cnt = 0;

        while(curr < n-1)
        {
            cnt++;
            curr = nums[curr];
        }  
        return cnt;      
    }
};