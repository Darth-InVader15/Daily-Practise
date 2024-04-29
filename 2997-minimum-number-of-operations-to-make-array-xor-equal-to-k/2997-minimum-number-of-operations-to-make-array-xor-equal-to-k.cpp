class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<32;i++)
        {
            int cnt1 = 0, cnt0 = 0;
            int flag = (k >> i) & 1; // is the bit set?
            for(int j=0;j<n;j++)
            {
                int ele = nums[j];

                if(ele >> i & 1)    cnt1++;
                else cnt0++;
            }
            if(!flag && (cnt1 % 2 == 0))  continue;
            if(flag && cnt1 & 1)    continue;
            else{
                ans++;
                // cout<<flag<<" "<<i<<" - "<<cnt0<<" "<<cnt1<<endl;
            }
        }
        return ans;
    }

};