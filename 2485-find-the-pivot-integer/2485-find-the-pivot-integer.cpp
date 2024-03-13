class Solution {
public:
    int pivotInteger(int n) {

        long long sum = (n*(n+1))/2;
        int lo = 0, hi = n;

        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;

            long long sum2 = (mid*(mid+1))/2;
            if(2*sum2 == sum+mid)   return mid;
            else if(2*sum2 > sum+mid)   hi = mid-1;
            else lo = mid+1;
        }
        return -1;
    }
};