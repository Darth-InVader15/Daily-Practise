class Solution {
    //similar to 523
    //trick here is in pref sum store sum%k
    //if 2 ele are same then in theory the subarr b/w them is divisible by k
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0,sum = 0, cnt=0;
        // vector<int> pre(n);
        unordered_map<int,int> mpp;
        // pre[0] = nums[0]%k;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            cnt = (sum)%k;

            if(cnt < 0) cnt += k;
            
            if(mpp[cnt] > 0) ans += mpp[cnt]; 
            if(cnt==0) ans++; 
            // cout<<i<<" "<<cnt<<" "<<mpp[cnt]<<endl;
            mpp[cnt]++;
        }
        return ans;


    }
};