class Solution {
public:
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
        //i wrote a recursive dp soln but 1e9 limit-_-
        //plus the dp arr would be 3d, the integer,cnt1 and cnt2
        
        int lo = 1, hi = INT_MAX;
        int ans = 0;
        
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            
            //this mid is the num we are considering as ans
            //So the no of nums before mid that are div by div1 = mid/div1
            
            int t1 = mid - (mid/div1);
            int t2 = mid - (mid/div2);
            
            //for ele that are div by both, they cant be taken in either
            int hcf = __gcd(div1,div2);
            long long lcm = (long long)(div1/hcf)*div2;
            
            long long t3 = mid - (mid/lcm);
            
            //Now, for mid to be ans, t1 t2 should be >= cnt1 cnt2
            //t3 has the numb of ele that is not in div1 intersection div2
            //so our tot cnt should be less that it
            
            if(t1>= cnt1 && t2 >= cnt2 && t3 >= (cnt1+cnt2))
            {
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
            
        }
        return ans;
        
    }
};