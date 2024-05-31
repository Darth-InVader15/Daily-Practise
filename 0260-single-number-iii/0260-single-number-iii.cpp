class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2,0);
        int num = nums[0];

        for(int i=1;i<nums.size();i++)  num ^= nums[i];

        int i=0;

        while(1)
        {
            if(num >> i & 1)    break;
            i++;
        }
        // ith bit is set
        vector<int> a,b;
        for(auto x: nums)
        {
            if(x>>i & 1)    a.push_back(x);
            else b.push_back(x);
        }
        int num1 = a[0], num2 = b[0];

        for(int i=1;i<a.size();i++) num1 ^= a[i];
        for(int i=1;i<b.size();i++) num2 ^= b[i];

        ans[0] = num1;
        ans[1] = num2;
        return ans;

    }
};