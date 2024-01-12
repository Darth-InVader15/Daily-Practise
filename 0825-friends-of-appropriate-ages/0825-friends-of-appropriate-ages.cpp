class Solution {
    bool chk(int i,int k,vector<int> &arr)
    {
        int a = arr[i];
        int b = arr[k];

        if(b>a || b <= (a/2) + 7)   return 0;
        return 1;
    }
    int binSrc(int i, vector<int> &ages)
    {
        int lo = 0;
        int hi = i-1;
        //we are searching for the min index that crosses the first criteria
        int ans = -1;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;

            if(chk(i,mid,ages))
            {
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;

    }
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        int cnt = 0;

        sort(ages.begin(),ages.end());

        for(int i=0;i<n;i++)
        {
            int a = 1;
            while(i<n-1 && ages[i] == ages[i+1])
            {
                a++;
                i++;
            }
            int ind = binSrc(i,ages);

            if(ind == -1) continue;
            cnt += (a*(i-ind));
            cout<<ind<<" "<<i<<endl;
        }
        return cnt;
    }
};