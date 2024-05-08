class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        auto arr = score;
        sort(arr.begin(),arr.end(),greater<int>());

        int n = arr.size();
        unordered_map<int,string> mpp;

        for(int i=0;i<n;i++)
        {
            if(i == 0)  mpp[arr[i]] = "Gold Medal";
            else if(i == 1) mpp[arr[i]] = "Silver Medal";
            else if(i == 2) mpp[arr[i]] = "Bronze Medal";
            else mpp[arr[i]] = to_string(i+1);
        }
        vector<string> ans;
        for(auto x:score)
        {
            ans.push_back(mpp[x]);
        }
        return ans;
        
    }
};