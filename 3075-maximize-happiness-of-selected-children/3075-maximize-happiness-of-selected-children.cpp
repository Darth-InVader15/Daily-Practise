class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end(),greater<int>());

        long long sum = 0;
        int n = arr.size();
        int t = 0;

        for(int i=0;i<n;i++)
        {
            if(t == k)  break;
            sum += max(arr[i]-t,0);
            t++;
        }
        return sum;
        
    }
};