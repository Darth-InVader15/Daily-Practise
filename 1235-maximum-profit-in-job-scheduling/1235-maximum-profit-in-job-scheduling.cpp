class Solution {
    static bool cstm(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])
        {   
            if(a[1] == b[1])
            {
                return a[2] > b[2]; //if same end, higher end should come first
            }
            return a[1] < b[1]; // lower end should come first
        }
        return a[0] < b[0];
    }
    
    //Binary Search the next ind for our dp
    int findNxt(int ind, vector<vector<int>> &arr)
    {
        int lo = ind;
        int hi = arr.size()-1;
        int ans = hi+1;
        
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid][0] >= arr[ind][1])
            {
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
    
    int solve(int ind,vector<vector<int>> &arr, vector<int> &dp)
    {
        if(ind == arr.size())  return 0;
        
        if(dp[ind] != -1)    return dp[ind];
        
        int take = 0, skip = 0;
        // if(lst == -1 || arr[lst][1] <= arr[ind][0])
        // {
        //     int nxtInd = findNxt(ind,arr);
        //     take = arr[ind][2] + solve(nxtInd,ind,arr,dp);
        // }
        int nxtInd = findNxt(ind,arr);
        take = arr[ind][2] + solve(nxtInd,arr,dp);
        skip = solve(ind+1,arr,dp);
        
        return dp[ind] = max(take,skip);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<int> dp(n,-1);
        vector<vector<int>> arr(n,vector<int>(3));
        
        for(int i=0;i<n;i++)
        {
            arr[i] = {startTime[i],endTime[i],profit[i]};
        }
        sort(arr.begin(),arr.end());
        
        return solve(0,arr,dp);
        // return solve(0,-1,startTime,endTime,profit,dp);
        
    }
};