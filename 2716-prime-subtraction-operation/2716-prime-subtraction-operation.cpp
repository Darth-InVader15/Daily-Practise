class Solution {
private:
    int findPrime(int a, int val)
    {
        for(int i=a-1;i>0;i--)
        {
            if(prime(i) && a-i > val) return i;
        }
        return 0;
    }
    int prime(int a)
    {
        if(a < 2) return 0;
        
        for(int i=2;i<a;i++)
        {
            if(a%i == 0) return 0;
        }
        return 1;
    }
public:
    bool primeSubOperation(vector<int>& nums) {

        int n = nums.size();
        
        // int a = findPrime(nums[0],-1);
        // nums[0] -= a;

        for(int i=0;i<=n-1;i++)
        {
            int a = findPrime(nums[i], (i>0) ? nums[i-1] : 0);
            nums[i] -= a;
            cout<<nums[i]<<endl;
            if((i<n-1 && nums[i] >= nums[i+1]) || (i>0 && nums[i] <= nums[i-1])) return 0;
        }
        return 1;
        
    }
};