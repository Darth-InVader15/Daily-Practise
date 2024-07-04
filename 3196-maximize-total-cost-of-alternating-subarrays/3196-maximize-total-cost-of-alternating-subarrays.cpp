class Solution {
    long long dp[100001];
    long long solve(int ind,vector<int> &arr)
    {
        if(ind >= arr.size())   return 0;

        if(dp[ind] != -1)   return dp[ind];

        long long ans = INT_MIN, sum = 0;
        for(int i=0;i<arr.size()-ind;i++)
        {
            if(i%2 == 0)    sum += arr[ind+i];
            else sum -= arr[ind+i];
            long long anss = sum + (dp[ind] == -1 ? solve(ind+i+1,arr) : dp[ind]);
            // long long anss = sum + ;

            // cout<<ind<<" "<<i<<" "<<sum<<" "<<anss<<" "<<ans<<endl;
            ans = max(ans,anss);
        }
        return dp[ind] = ans;
    }
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i=0;i<n;i++)    if(nums[i]<0){
            s=1;
            break;
        }
        if(!s) return accumulate(nums.begin(),nums.end(),0);    
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
        
    }
};