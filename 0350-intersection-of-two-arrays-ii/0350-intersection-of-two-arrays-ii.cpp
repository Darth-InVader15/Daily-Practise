class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mpp1,mpp2;

        for(auto x:nums1)   mpp1[x]++;
        for(auto x:nums2)   mpp2[x]++;

        for(auto x:nums1) if(mpp1[x] > 0 && mpp2[x]>0){
            for(int i=0;i<min(mpp1[x],mpp2[x]);i++)
                ans.push_back(x);
            
            mpp1[x] = mpp2[x] = 0;
        }
        return ans;
    }
};