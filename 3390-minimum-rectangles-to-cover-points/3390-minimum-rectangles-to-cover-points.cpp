class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n=points.size();
        vector<int> x(n,-1);
        for(int i=0; i<n; i++) x[i]=points[i][0];
        sort(x.begin(), x.end());
        int ans=0, k=0;
        while(k<n){
            k=upper_bound(x.begin()+k, x.end(), x[k]+w)-x.begin();
            ans++;
        } 
        return ans; 
    }
};