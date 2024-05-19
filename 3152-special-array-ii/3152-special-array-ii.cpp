class Solution {
    bool srch(vector<int> &q, vector<int> &sp)
    {
        int lo = 0, hi = sp.size()-1;
        int lb = -1;
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            if(sp[mid] >= q[0])
            {
                lb = mid;
                hi = mid-1;
                // if(sp[mid]+1 <= q[1])   return 1;
            }
            else lo = mid+1;
        }
        if(lb == -1)    return 0;
        lo = 0, hi = sp.size()-1;
        int ub = sp.size()-1;
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            if(sp[mid]+1 <= q[1])
            {
                ub = max(ub,mid); // max ele that is less than q[i]+1
                lo = mid+1;
            }
            else hi = mid-1;
        }
        // cout<<lb<<" "<<ub<<endl;
        for(int i=lb;i<=ub;i++)
        {
            if(sp[i]+1 <= q[1])  return 1;
        }
        
        return 0;
    }
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        // vector<vector<int>> sp;
        vector<int> sp;

        for(int i=1;i<n;i++)
        {
            if((nums[i] ^ nums[i-1]) & 1)   continue;
            // else sp.push_back({i-1,i});
            else    sp.push_back(i-1); 
        }
        // for(auto x:sp)  cout<<"--"<<x<<endl;
        vector<bool> ans(q.size(),false);
        for(int i=0;i<q.size();i++)
        {
            auto x = q[i];
            if(!srch(x,sp))  ans[i] = 1;
        }
        return ans;
        
    }
};