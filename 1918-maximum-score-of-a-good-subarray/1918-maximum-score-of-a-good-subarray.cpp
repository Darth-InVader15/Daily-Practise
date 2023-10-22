class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = nums[k];
        int minn = nums[k];
        
        int i = k, j = k;

        while(i>0 || j <n)
        {
            if(i == 0)
            {
                minn = min(minn,nums[j]);
                ans = max(ans,minn*(j+1));
                j++;
                continue;
            }
            if(j >= n)
            {
                minn = min(minn,nums[i]);
                ans = max(ans,minn*(n-i));
                i--;
                continue;
            }

            int a = nums[i-1];
            int b = nums[j+1];

            

            if(a>b)
            {
                i--;
                minn = min(minn,a);
                ans = max(ans,minn*(j-i+1));
                // cout<<i<<" "<<j<<" "<<minn<<" "<<ans<<"\n";
            }
            else
            {
                j++;
                minn = min(minn,b);
                ans = max(ans,minn*(j-i+1));
                // cout<<i<<" "<<j<<" "<<minn<<" "<<ans<<"\n";
            }
        }
        return ans;
        
    }
};