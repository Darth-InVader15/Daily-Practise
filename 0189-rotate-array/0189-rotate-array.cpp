class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if(k > n)   k = k%n;
        if(k == 0 || k == n)    return;
        
        int lt = n - k;
        vector<int> temp(nums.begin()+lt,nums.end());

        for(int i=lt-1;i>=0;i--)  
        {
            // cout<<i<<" "<<nums[i]<<endl;
            nums[i+k] = nums[i];
        }
        for(int i=0;i<k;i++)    nums[i] = temp[i];
        
    }
};