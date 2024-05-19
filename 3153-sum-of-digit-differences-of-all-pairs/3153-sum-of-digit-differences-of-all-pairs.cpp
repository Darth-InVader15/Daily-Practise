class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        //brute force
        //n size vector<vector<int>> banao -- n is the no of digits in a num
        //idk, pair wise do index leke match kar sakte hai, lekin that would be On^2 per digit
        //also, we can sort each digit arr, 
        // better way, n arrays of size 11, 10 being the count of each digit and 11th being their sum
        // then for each digit with freq > 0, increment ans by tot - freq
        int num = nums[0];
        int n = 0;

        while(num)
        {
            num /= 10;
            n++;
        } 
        vector<vector<int>> arr(n,vector<int>(11,0));
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                int d = nums[i]%10;
                arr[j][d]++;
                arr[j][10]++;
                nums[i]/=10;
            }
        }
        long long ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<10;j++){
                if(!arr[i][j])  continue;
                
                ans += (arr[i][10]-arr[i][j])*arr[i][j];
                arr[i][10] -= arr[i][j];
            }  
        }
        return ans;

    }
};