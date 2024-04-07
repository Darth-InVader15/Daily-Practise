class Solution {
private:
    int binSrch(vector<int> &arr,int ind, int tar)
    {
        int lo = ind+1, hi = arr.size()-1;

        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;

            if(arr[mid] == tar) return mid;
            else if(arr[mid] > tar) hi = mid-1;
            else lo = mid+1;
        }
        return -1;
        
    }
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        int n = arr.size();

        for(int i=0;i<n;i++)
        {
            int x = binSrch(arr,i,tar-arr[i]);
            if(x != -1) return {1+i,1+x};
        }
        return {-1,-1};
    }
};