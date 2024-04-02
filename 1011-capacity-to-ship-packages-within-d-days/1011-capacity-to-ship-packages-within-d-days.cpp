class Solution {
public:
    int shipWithinDays(vector<int>& arr, int days) {
        int lo = 0, hi = 0;
        int n = arr.size();

        for(auto x:arr)
        {
            lo = max(lo,x);
            hi += x;
        }
        int ans = 1e9;
        //lo would be max ele in the arr and hi would be their sum
        //but finding that would be a O(n) operation

        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            // cout<<mid<<"--mid\n";

            int sum = 0;
            int endd = 0, day = 0;
            while(endd < n)
            {
                while(endd < n && sum <= mid)
                {
                    sum += arr[endd++];
                    // cout<<sum<<" -- "<<endd<<"\n";
                }
                if(endd == n) //mid is enough to accomodate all the days
                {
                    day++;
                    if(sum > mid)   day++;
                }
                else //we increment the day
                {
                    day++;
                    sum = arr[endd-1];
                }
                // cout<<day<<" d---e "<<sum<<" "<<endd<<endl;
            }

            if(day <= days)
            {
                ans = min(ans,mid);
                hi = mid-1;
            }
            else    lo = mid +1;

        }
        return ans;

        
    }
};