class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        //delete 2 random ele from the fist arr and then verify for the entire length
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n = nums1.size(), m = nums2.size();
        set<pair<int,int>> vis;
        int ans = 1e9;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j == i)  continue;
                if(vis.count({min(i,j),max(i,j)}))  continue;
                vis.insert({i,j});
                int k1 = 0, k2 = 0;
                int diff = -1;
                while(k2 < m)
                {
                    while(k1 == i || k1 == j) k1++;

                    // cout<<i<<" -- "<<j<<" "<<k1<<" "<<k2<<endl;

                    if(diff == -1)  diff = nums2[k2] - nums1[k1];
                    else if (diff != (nums2[k2]-nums1[k1])) break;

                    if(k2 == m-1)
                    ans = min(ans, nums2[k2]-nums1[k1]);
                    k1++;
                    k2++;
                }
            }
            
        }
       
        return ans;
        return min({nums2[0]-nums1[2], nums2[0]-nums1[1], nums2[0]-nums1[0]});

        
    }
};