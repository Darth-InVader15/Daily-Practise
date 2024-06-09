class Solution {
int solve(vector<int> &arr, int mid)
{
    int cnt = 0;
    int n = arr.size();
    int curr = 0, i=0;

    while(curr <= mid && i<n)
    {
        while(i<n && curr+arr[i] <= mid)
        {
            // cout<<curr<<" "<<arr[i]<<" "<<i<<endl;
            curr+=arr[i];
            i++;
            if(i==n)    cnt++;
        }
        if(i<n && curr+arr[i] > mid)
        {
            cnt++;
            curr = 0;
            // i++;
        }
    }
    return cnt;
}
public:
    int shipWithinDays(vector<int>& wts, int days) {
        int hi = 1e9;
        int lo = *max_element(wts.begin(),wts.end());
        int ans = 0;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            cout<<mid<<" "<<solve(wts,mid)<<endl;
            if(solve(wts,mid) <= days)
            {
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};