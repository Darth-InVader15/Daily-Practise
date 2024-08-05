class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mpp;
        // vector<string> ans;

        for(auto x:arr)
        {
            mpp[x]++;
        }
        for(auto x:arr)
        {
            if(mpp[x] == 1) k--;
            if(k == 0)  return x;
        }
        return "";
        
    }
};