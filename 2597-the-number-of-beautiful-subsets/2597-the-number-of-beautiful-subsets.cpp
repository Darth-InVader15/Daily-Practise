class Solution {
    bool check(int k, unordered_map<int,int> &mpp,int num)
    {
        //abs(num - x) == k nhi hona chahie
        //x = num - k || x = num + k
        if(mpp[num+k] > 0 || mpp[num-k] > 0)    return 0;
        return 1;
    }
    int solve(int ind, vector<int> &nums, unordered_map<int,int> &ele,int k,map<pair<vector<int>,int>,int> &stt)
    {
        if(ind == nums.size())  return ele.size() > 0;
        
        // if(stt.count({ele,ind}))    return stt[{ele,ind}];

        int take = 0, dont = 0;
        //take this curr ele if its diff with other ele of ele array is not K
        if(check(k,ele,nums[ind]))
        {
            ele[nums[ind]]++;
            // ele.push_back(nums[ind]);
            take = solve(ind+1,nums,ele,k,stt);
            // ele.pop_back();
            ele[nums[ind]]--;
        }
        dont = solve(ind+1,nums,ele,k,stt);

        // return stt[{ele,ind}] = take+dont;
        return take+dont;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> ele;
        unordered_map<int,int> mpp;
        map<pair<vector<int>,int>,int> stt;
        return solve(0,nums,mpp,k,stt)-1;
    }
};