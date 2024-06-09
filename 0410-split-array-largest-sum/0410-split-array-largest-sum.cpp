class Solution {
    int pos(vector<int>&arr, int k,int m)
    {
        // return 0;
        int n = arr.size();
        //we want k subarrs with sum upto m
        int i=0, sum=0;
        int cnt = 0;
        cout<<"---"<<m<<endl;
        while(i<n)
        {
            while(i<n && sum+arr[i] <= m)
            {
                sum += arr[i];
                cout<<sum<<" "<<i<<" "<<arr[i]<<endl;
                i++;
            }
            if(i == n || sum + arr[i] > m)
            {
                
                sum = 0;
                // i++;
                cnt++;
            }
            // if(k==0 && i)    break;
        }
        return cnt;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        //somewhat like agressive cows
        //we perform BS oveer all the sums

        int lo = *max_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;

            int res = pos(nums,k,mid);

            if(res <= k)
            {
                ans = mid;
                hi = mid-1;
            }
            else // we need to increase the sum
            {
                // ans = mid;
                lo = mid+1;
            }
            // else hi = mid-1;
        }
        return ans;
    }
};