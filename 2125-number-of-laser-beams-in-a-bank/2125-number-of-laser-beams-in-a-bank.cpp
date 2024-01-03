class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();

        vector<int> arr(n);
        int i=0;

        for(auto x:bank)
        {
            int cnt = 0;
            for(auto y:x) 
            {
                if(y=='1')  cnt++;
            }  
            arr[i] = cnt;
            i++;
        }
        int prev = -1;
        int ans = 0;
        for(auto x:arr)
        {
            if(x == 0) continue;
            if(prev == -1) prev = x;

            else
            {
                ans += (prev*x);
                prev = x;                
            }
        }
        return ans;
        
    }
};