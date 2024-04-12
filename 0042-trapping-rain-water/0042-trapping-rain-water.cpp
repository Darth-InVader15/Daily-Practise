class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n), suf(n);

        pre[0] = -1;
        int maxx = height[0];
        for(int i=1;i<n;i++)
        {
            pre[i] = maxx;
            maxx = max(maxx,height[i]);
        }
        suf[n-1] = -1;
        maxx = height[n-1];

        for(int i=n-2;i>=0;i--)
        {
            suf[i] = maxx;
            maxx= max(maxx,height[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            maxx = min(suf[i],pre[i]);

            ans += maxx > height[i] ? maxx-height[i] : 0;
        }
        return ans;
    }
};