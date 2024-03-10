class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> stt1(nums1.begin(),nums1.end()), stt2(nums2.begin(),nums2.end());
        vector<int> ans;
        for(auto itr:stt1)
        {
            if(stt2.find(itr) != stt2.end())  ans.push_back(itr);
        }

        return ans;
        
    }
};