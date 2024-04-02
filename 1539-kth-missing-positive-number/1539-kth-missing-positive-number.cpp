class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0;
        int n = arr.size();

        for(int i=0;i<n;i++)
        {
            if(arr[i] > lo)
            {
                if(k - (arr[i]-lo) < 0)
                {
                    break;
                }
                else
                {
                    k -= ((arr[i]-lo)-1);
                    lo = arr[i];
                }
            }
        }
        return lo + k;
    }
};