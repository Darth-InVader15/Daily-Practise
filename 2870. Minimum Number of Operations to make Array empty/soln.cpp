class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        vector<int> arr(1e6+1,0);
        
        for(auto x:nums)
            arr[x]++;
        
        for(auto x:arr)
        {
            if(!x) continue;
            if(x == 1)  return -1;
            
            
            int cnt = 0;
            cnt += x/3;
            x = x%3;
            if(x%2 != 0)
            {
                cnt--;
                x += 3;
            }
            cnt += x/2;
            
            ans += cnt;
        }
        return ans;
    }
};

// x = 2a + 3b
// x = 11, -> b = x/3, a = (x%3)/2