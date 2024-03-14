class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int goal) {
        int cnt = 0, n = arr.size();

        unordered_map<int,int> mpp;
        vector<int> pre(n,0);
        pre[0] = arr[0];
        mpp[pre[0]]++;

        for(int i=1;i<n;i++)
        {
            pre[i] = pre[i-1]+arr[i]; 
            mpp[pre[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            if(mpp.find(goal+pre[i]) != mpp.end())
            {
                cnt += mpp[pre[i] + goal];
                if(goal + pre[i] == pre[i]) cnt -= 1;
            }
            if(pre[i] == goal)  cnt++;
            mpp[pre[i]]--;
            // cout<<goali<<" "<<mpp[goal+i]<<" "<<pre[i]<<" "<<
        }
        return cnt;
        
    }
};