class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int cnt = 0;
        int n = s.size(), m = g.size();
        int i = 0, j = 0;
        while(i < m && j < n)
        {
            if(g[i] <= s[j])
            {
                cnt++;
                i++;
            }
            j++;

        }
        return cnt;
    }
};