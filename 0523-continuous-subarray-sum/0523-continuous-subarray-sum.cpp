class Solution {
    //well this is something new and awesome to learn
//     Basically you want to create an array of the accumulated sum, but instead of the sum, you have the sum%k. If you just go through it normally and return on sum%k == 0, then that only accounts for (n) possibilities out of (n^2) possibilities. However, if you find duplicated sum%k values, then that the sub array between those two indexes will actually be the solution.

// i.e.
// [4, 1, 2, 3] and 6

// if we get the accumulated sum, it looks like this [4, 5, 7, 10]
// if we make it accumulated sum % k, it looks like this [4, 5, 1, 4]
// notice that there is duplicated 4's. The diffference between these two sums in theory must be a multiple of 6 since we've only been storing the num%k.
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        int n = nums.size();
        int sum = 0, cnt = 0;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            cnt = sum%k;

            if(mpp.find(cnt) == mpp.end())  mpp[cnt] = i;
            else if((i-mpp[cnt] > 1))   return 1;  
        }
        return 0;


        //O(n*n) solution gives TLE
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=i+1;j<=n;j++)
        //     {
        //         if((j-i) >=2  && (pre[j] - pre[i]) % k  == 0)   return 1;
        //     }
        // }
        
        return 0;
    }
};