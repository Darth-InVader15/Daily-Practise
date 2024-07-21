class Solution {
    bool static cstm(pair<int,int>&a,pair<int,int>&b)
    {
        //we want more cnt or less diff
        if(a.first == b.first)  return a.second < b.second;
        return a.first > b.first;
    }
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(k+1), range(n/2);
        vector<pair<int,int>> temp;
        for(int i=0;i<n/2;i++)
        {
            int a = nums[i], b = nums[n-i-1];
            int res = abs(a-b);
            int lt = max({b,a,k-a,k-b,abs(b-a)});
            arr[res]++;
            range[i] = lt;
        }
        for(int i=0;i<=k;i++)
        {
            if(arr[i])
            {
                temp.push_back({arr[i],i});//arr[i] is cnt, i is the diff x
            }
        }

        // for(auto x:temp)    cout<<x.first<<" "<<x.second<<"-\n";
        // for(auto x:range)   cout<<x<<"------\n";
        // for(auto x:arr)     cout<<x<<" is\n";

        sort(temp.begin(),temp.end(),cstm);
        sort(range.begin(),range.end());
        int ans = 1e9;

        
        // range[0] = 2;
        for(int i=0;i<=k;i++)
        {
            //plusTwo returns ind of the first ele whose range is greater/equal than our res
            //arr[i] is the no of ele whose x is same as i
            // if(arr[i] == 0) continue;//dont bother if this x isnt initially there
            int plusTwo = lower_bound(range.begin(),range.end(),i)-range.begin();
            int res = (n/2) - (arr[i]+plusTwo); //itna ele 1 khayega
            res += (2*plusTwo); //itna ele 2 khayega

            // cout<<i<<" "<<arr[i]<<" "<<plusTwo<<" "<<res<<endl;
            ans = min(ans,res);

        }
        return ans;
    }
};